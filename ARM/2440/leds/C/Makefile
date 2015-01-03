CC := arm-linux-gcc
LD := arm-linux-ld
OBJCP := arm-linux-objcopy
OBJDUMP := arm-linux-objdump

led_china.bin: crt0.S  led_china.c
	$(CC) -g -c -o crt0.o crt0.S
	$(CC) -g -c -o led_china.o led_china.c
	$(LD) -Ttext 0x0000000 -g  crt0.o led_china.o -o key_led_elf
	$(OBJCP) -O binary -S key_led_elf led_china.bin
	$(OBJDUMP) -D -m arm  key_led_elf > led_china.dis
	
clean:
	rm -f led_china.dis led_china.bin key_led_elf *.o
