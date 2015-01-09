boot.bin : boot.elf
	arm-linux-objcopy -O binary $^ $@

boot.elf : boot.o  nand.o signal.o f.o
	arm-linux-ld -Tboot.lds $^ -o $@

boot.o : boot.S
	arm-linux-gcc -c $^ -o $@

nand.o : nand.c
	arm-linux-gcc -c $^ -o $@

signal.o : signal.c
	arm-linux-gcc -c $^ -o $@

f.o : f.c 
	arm-linux-gcc -c $^ -o $@

.PHONY : clean showobj
showobj :
	arm-linux-objdump -D boot.elf

clean:
	rm -f *.o *.elf *.bin
