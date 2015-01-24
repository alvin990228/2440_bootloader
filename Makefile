
boot.bin : boot.elf
	arm-linux-objcopy -O binary $^ $@

boot.elf : boot.o  nand.o f.o keys.o led.o uart.o beep.o
	arm-linux-ld -Tboot.lds $^ -o $@

boot.o : boot.S
	arm-linux-gcc -c $^ -o $@

nand.o : nand.c
	arm-linux-gcc -c $^ -o $@

f.o : f.c 
	arm-linux-gcc -c $^ -o $@

keys.o : keys.c
	arm-linux-gcc -c $^ -o $@
	
led.o : led.c
	arm-linux-gcc -c $^ -o $@

uart.o : uart.c
	arm-linux-gcc -c $^ -o $@

beep.o : beep.c
	arm-linux-gcc -c $^ -o $@

.PHONY : clean showobj
showobj :
	arm-linux-objdump -D boot.elf

clean:
	rm -f *.o *.elf *.bin
