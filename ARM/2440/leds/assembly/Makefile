AS = arm-linux-as
LD = arm-linux-ld
OJ = arm-linux-objcopy

AS_FLAGS = -mcpu=arm9tdmi --gdwarf2 -o
OJ_FLAGS = -O binary -S

all: LED_SHIFT_BIN

LED_SHIFT_BIN: LED_SHIFT
	$(OJ) $(OJ_FLAGS) $^ $@

LED_SHIFT: LED DELAY
	$(LD) -o $@ $^

LED:
	$(AS) $(AS_FLAGS) $@ led_shift.asm

DELAY:
	$(AS) $(AS_FLAGS) $@ delay.asm

clr:
	rm LED DELAY LED_SHIFT LED_SHIFT_BIN
