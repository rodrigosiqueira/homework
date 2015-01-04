AS = arm-linux-as
LD = arm-linux-ld
OBJCOPY = arm-linux-objcopy

ASFLAGS = -mcpu=arm9tdmi --gdwarf2 -o
OBJCOPYFLAGS = -O binary -S

all: led_shift.bin turn_on.bin

led_shift.bin: led_shift.o
	$(OBJCOPY) $(OBJCOPYFLAGS) $^ $@

turn_on.bin: turnOn.asm
	$(AS) $(ASFLAGS) $@ $^

led_shift.o: led.o delay.o
	$(LD) -o $@ $^

led.o:
	$(AS) $(ASFLAGS) $@ led_shift.asm

delay.o:
	$(AS) $(ASFLAGS) $@ delay.asm

clean:
	rm -rf *.o *.bin
