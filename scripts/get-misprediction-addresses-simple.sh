#!/usr/bin/env bash

# Gets addresses of flips associated with mispredictions

python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 1 misprediction-addresses > mispredict-address-size-1.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 2 misprediction-addresses > mispredict-address-size-2.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 3 misprediction-addresses > mispredict-address-size-3.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 4 misprediction-addresses > mispredict-address-size-4.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 5 misprediction-addresses > mispredict-address-size-5.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 6 misprediction-addresses > mispredict-address-size-6.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 7 misprediction-addresses > mispredict-address-size-7.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 8 misprediction-addresses > mispredict-address-size-8.csv