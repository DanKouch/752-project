# Evaluating the Fault Tolerance of Embedded Binarized Neural Networks

## Setup

To clone archie and ebnn with this repository, make sure to clone with `--recurse-submodules`. EBNN doesn't require any setup, but Archie requires extensive setup which is described in it's README.

The `run-target` make rule in `src/` requires QEMU to be installed on your system, and the `gdb-target` rule requires gdb-multiarch to be installed.

## Folder Structure


### `src/`
This directory contains code used to generate executables, both for the host and the target. The makefile in this directory contains a variety of useful rules listed as follows

- `make host [simple_mnist|binary_mnist]`
  - Generates an executable the host can run
- `make run-host [simple_mnist|binary_mnist]`
  - Runs the executable on the host
- `make target [simple_mnist|binary_mnist]`
  - Generates an executable for the STM32LVDISCOVERY that QEMU can run
- `make run-target [simple_mnist|binary_mnist]`
  - Runs the taget executable in QEMU
  - Since QEMU won't be able to output anything, this should be preceded by running `make gdb-target` in another terminal to retreive the output arrays
- `make archie [simple_mnist|binary_mnist]`
  - Runs ARCHIE with the specified fault/qemuconf script


### `out/`
This directory contains generated `.elf` and `.out` executables

### `scripts/`
This code contains code used for data analysis.
The `.sh` files use `modified-executable-tests.py` to generate CSV for experiments related to changing the executable directly.

The Jupiter notebook contains code used to analyze results from ARCHIE tests.