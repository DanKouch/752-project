HOST_CC := gcc
TARGET_CC :=arm-none-eabi-gcc
LDSCRIPT = ./stm32f0-discovery.ld
INCLUDES = -I. -I../ebnn/c -I../ebnn/examples

PROG := alex

host: $(PROG).c $(PROG).h
	mkdir -p ../out
	$(HOST_CC) -g -Os $(INCLUDES) -DHOST -o ../out/$(PROG).out $(PROG).c

target: $(PROG).c $(PROG).h
	mkdir -p ../out
	$(TARGET_CC) -g -Os $(INCLUDES) -mcpu=cortex-m0 -mthumb -Wl,-static,-Map=../out/$(PROG).map  -nostartfiles -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group -Wl,-T,$(LDSCRIPT) $(PROG).c -o ../out/$(PROG).elf

get-addresses:
	gdb-multiarch -ex 'print &done' -ex 'print &train_labels' -ex 'print &output' -ex quit ../out/$(PROG).elf | tail -3

run-host:
	../out/$(PROG).out

run-target:
	qemu-system-arm -nographic -machine stm32vldiscovery -kernel ../out/$(PROG).elf -s -S

gdb-target:
	gdb-multiarch -ex 'target remote localhost:1234' -ex 'b done' -ex 'c' -ex 'p output' -ex 'p labels' -ex 'set confirm off' -ex 'quit' ../out/$(PROG).elf

archie:
	rm -f ../out/*.xz
	rm -f ../out/log_*.txt
	rm -f ../out/*.hdf5
	(cd ../out && python ../archie/controller.py --fault ../src/fault-$(PROG).json  --qemu ../src/qemuconf-$(PROG).json output.hdf5)
	rm -f ../out/log_*.txt

clean:
	rm -f *.elf
	rm -f *.map
	rm -f *.out
	rm -f *.txt
	rm -f *.hdf5
	rm -f *.xz
	rm -f -r ../out/*