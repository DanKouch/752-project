# Usage: python3 modify-objectfile.py [objectfile] [address start] [length] [fault_size] [output-type]

import sys
import shutil
import math
import os
import stat
import subprocess
import json

if(len(sys.argv) != 6):
    print("Usage: python3 modify-objectfile.py [objectfile] [address start] [length] [fault_size] [output-type]")
    exit(1)

objectfile_path = sys.argv[1]
address_start = int(sys.argv[2], 16)
length = int(sys.argv[3])
fault_size = int(sys.argv[4])
output = sys.argv[5]

## Output types:
# debug : Print JSON and counts
# count : Print counts as CSV lines
# l2-norms : Print L2 norms for every anomalous run
# json : Print JSON of comparision

tmp_path = "./_temp.obj"


def getFlipMask(address, size):
    bytes_needed = math.ceil(((address % 8) + size) / 8)

    str_mask = ""
    str_mask += "0" * (address % 8)
    str_mask += "1" * size
    str_mask += "0" * ((bytes_needed * 8) - len(str_mask))

    return int(str_mask, 2).to_bytes(bytes_needed, byteorder='big')

def processOutput(output):
    out = {
        "tests": [None] * 20,
        "correct": 0
    }
    
    lines = output.splitlines()
    
    # Per experiment
    for test in range(0, 20):
        out["tests"][test] = {
            "res": []
        }
        for classification in range(0, 10):
            line = lines[test*10 + classification].split(",")
            out["tests"][test]["res"].append(float(line[4]))
            if(int(line[2])):
                out["tests"][test]["label"] = classification
            if(int(line[3])):
                out["tests"][test]["prediction"] = classification
        out["tests"][test]["correct"] = out["tests"][test]["label"] == out["tests"][test]["prediction"]
        if(out["tests"][test]["correct"]):
            out["correct"] += 1

    return out

def compare_data(run_data, goldenrun_data):

    comparision = {
        "exact": str(run_data) == str(goldenrun_data)
    }

    if(comparision["exact"]):
        return comparision

    comparision["correct_matches"] = run_data["correct"] == goldenrun_data["correct"]
    comparision["predictions_mismatches"] = 0
    comparision["labels_mismatches"] = 0

    comparision["max_pct_diff"] = 0
    comparision["max_l2norm"] = 0
    comparision["sum_l2norm"] = 0

    comparision["tests"] = []
    for test in range(0, 20):
        if(str(run_data["tests"][test]) == str(goldenrun_data["tests"][test]) and comparision["correct_matches"]):
            continue

        test_comparision = {
            "test": test,
            "labels_match": run_data["tests"][test]["label"] == goldenrun_data["tests"][test]["label"],
            "predictions_match": run_data["tests"][test]["prediction"] == goldenrun_data["tests"][test]["prediction"],
            "l2norm": 0.0,
            "res": []
        }

        if(not test_comparision["labels_match"]):
            comparision["labels_mismatches"] += 1

        if(not test_comparision["predictions_match"]):
            comparision["predictions_mismatches"] += 1

        for classification in range(0, 10):
            run_res = run_data["tests"][test]["res"][classification]
            goldenrun_res = goldenrun_data["tests"][test]["res"][classification]
            test_comparision["l2norm"] += math.pow(goldenrun_res - run_res, 2)

            # Only detect a difference if its above 0.1%
            pct_diff = (abs(goldenrun_res - run_res)/max(goldenrun_res, run_res))*100
            if(pct_diff > 0.1):
                test_comparision["res"].append({
                    "classification": classification,
                    "run_res": run_res,
                    "goldenrun_res": goldenrun_res,
                    "percent_diff": pct_diff
                })
            if(pct_diff > comparision["max_pct_diff"]):
                comparision["max_pct_diff"] = pct_diff

        test_comparision["l2norm"] = math.sqrt(test_comparision["l2norm"])
        if(test_comparision["l2norm"] > comparision["max_l2norm"]):
            comparision["max_l2norm"] = test_comparision["l2norm"]
        comparision["sum_l2norm"] += test_comparision["l2norm"]
        
        if(test_comparision["labels_match"] and test_comparision["predictions_match"] and len(test_comparision["res"]) == 0):
            continue
        
        comparision["tests"].append(test_comparision)

    if(comparision["labels_mismatches"] == 0 and comparision["predictions_mismatches"] == 0 and len(comparision["tests"]) == 0):
        comparision["exact"] = True

    return comparision


# Get goldenrun
proc = subprocess.run(objectfile_path, capture_output = True)
goldenrun_data = processOutput(proc.stdout.decode())
#print(json.dumps(goldenrun_data, indent=1))

anomalies = []

for i in range(address_start, address_start + length - fault_size + 1):
    modify_start = i                    # Address to start flipping at
    modify_end = i + fault_size - 1    # Address to end flipping at

    shutil.copyfile(objectfile_path, tmp_path)
    with open(tmp_path, mode='rb+') as tmpfile:

        mask = getFlipMask(modify_start, fault_size)   

        #print("Flip mask:")
        #print(' '.join(f'{x:08b}' for x in mask)) # Print flip mask
        
        tmpfile.seek((modify_start // 8)*8)
        read_data = tmpfile.read(len(mask))
        #print("Original:")
        #print(' '.join(f'{x:08b}' for x in read_data)) # Print original data in file

        #print("Flipped")
        flippedData = bytes(x ^ y for x, y in zip(read_data, mask))
        #print(' '.join(f'{x:08b}' for x in flippedData)) # Print flipped data

        # Write data back to file
        tmpfile.seek((modify_start // 8)*8)
        tmpfile.write(flippedData)

    with open(tmp_path, mode="rb") as tmpfile:
        tmpfile.seek((modify_start // 8)*8)
        read_data = tmpfile.read(len(mask))
        #print("Final")
        #print(' '.join(f'{x:08b}' for x in read_data)) # Print original data in file

    # DEBUG: Generate an object file for each run
    shutil.copyfile(tmp_path, f"{modify_start}_{fault_size}.obj")

    os.chmod(tmp_path, os.stat(tmp_path).st_mode | stat.S_IEXEC)
    proc = subprocess.run("./_temp.obj", capture_output = True)
    run_data = processOutput(proc.stdout.decode())

    comparision = compare_data(run_data, goldenrun_data)
    
    if(not comparision["exact"]):
        comparision["modify_start"] = modify_start
        comparision["fault_size"] = fault_size
        del comparision["exact"]
        if(comparision["correct_matches"] and comparision["labels_mismatches"] == 0 and comparision["predictions_mismatches"] == 0):
            del comparision["tests"]
        anomalies.append(comparision)

stats = {
    "labels_dont_match": 0,
    "predictions_dont_match": 0,
    "labels_dont_match_total": 0,
    "predictions_dont_match_total": 0
}

for anomaly in anomalies:
    if(not (anomaly["labels_mismatches"] == 0)):
        stats["labels_dont_match_total"] += anomaly["labels_mismatches"]
        stats["labels_dont_match"] += 1
    if(not (anomaly["predictions_mismatches"] == 0)):
        stats["predictions_dont_match_total"] += anomaly["predictions_mismatches"]
        stats["predictions_dont_match"] += 1
    del anomaly["fault_size"]
    del anomaly["correct_matches"]
    
    # Output CSV line for l2 norms
    if(output == "l2-norms"):
        print(f"{anomaly['modify_start']},{anomaly['sum_l2norm']}")

if(output == "debug" or output == "json"):
    print(json.dumps(anomalies, indent=1))

if(output == "debug"):
    print(f"Detected {len(anomalies)} anomalies.")
    print(f"Labels didn't match {stats['labels_dont_match']} times. ({stats['labels_dont_match_total']} TOTAL)")
    print(f"Predictions didn't match {stats['predictions_dont_match']} times. ({stats['predictions_dont_match_total']} TOTAL)")

# Output CSV line for counts
if(output == "counts"):
    print(f"{fault_size}, {len(anomalies)},{stats['predictions_dont_match']},{stats['predictions_dont_match_total']}")