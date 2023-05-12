#!/usr/bin/env bash

# Gets the L2 norms for different fault sizes at different addresses of modification

python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 1 l2-norms > fault-size-1.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 2 l2-norms > fault-size-2.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 3 l2-norms > fault-size-3.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 4 l2-norms > fault-size-4.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 5 l2-norms > fault-size-5.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 6 l2-norms > fault-size-6.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 7 l2-norms > fault-size-7.csv
python3 modified-executable-tests.py ../out/simple_mnist_csv_output.out 0x12580 1128 8 l2-norms > fault-size-8.csv