HOST_CC := gcc
TARGET_CC :=arm-none-eabi-gcc
LDSCRIPT = ./stm32f0-discovery.ld
INCLUDES = -I. -I../ebnn/c -I../ebnn/examples

host:
	$(HOST_CC) -g -O0 $(INCLUDES) -DHOST -o alex.out alex.c

target:
	$(TARGET_CC) -g -O0 $(INCLUDES) -mcpu=cortex-m0 -mthumb -Wl,-static,-Map=alex.map  -nostartfiles -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group -Wl,-T,$(LDSCRIPT) alex.c -o alex.elf

get-addresses:
	gdb -ex 'print &done' -ex 'print &train_labels' -ex 'print &output' -ex quit ./alex.elf | tail -3

run-target:
	qemu-system-arm -nographic -machine stm32vldiscovery -kernel alex.elf -s -S

gdb-target:
	gdb-multiarch -ex 'target remote localhost:1234' -ex 'b done' -ex 'c' -ex 'p output' -ex 'p train_labels' -ex 'set confirm off' -ex 'quit' ./alex.elf

clean:
	rm *.elf
	rm *.map
	rm *.out