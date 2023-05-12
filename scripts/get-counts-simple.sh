#!/usr/bin/env bash

# Get counts for total anomalies, prediction mismatches, and total prediction mismatches

rm -f counts.csv
echo "Fault Size,Total Anomalies, Prediction Mismatches (1 Spoils), Prediction Mismatches (All)" >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 1 counts >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 2 counts >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 3 counts >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 4 counts >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 5 counts >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 6 counts >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 7 counts >> counts.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 8 counts >> counts.csv