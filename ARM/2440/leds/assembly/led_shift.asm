@Main file responsable for make the lads shift.
@This file will be linked with delay.asm
.global _start
_start:
	B main

.section LED_SHIFT
.data
.set GPBCON, 0x56000010
.set GPBDAT, 0X56000014
.set CST, 0x7FF

.text
main:
	@Configures GPBCON
	MOV r0, #0x15400
	LDR r1, =GPBCON
	STR r0, [r1]

	@Turn off all leds
	LDR r2, =CST
	LDR r1, =GPBDAT
	STR r2, [r1]
	
loop:
	@Base value for execute the shift
	MOV r0, #0x7E0
	ADD r0, #0XF
	
	@Turn on led: 5
	BL shifter_left
	
	@Turn on led: 6
	BL shifter_left
	
	@Turn on led: 7
	BL shifter_left

	@Turn on led: 8
	BL shifter_left

	@Turn on led: 7
	BL shifter_right

	@Turn on led: 6
	BL shifter_right

	@Turn on led: 5
	BL shifter_right
	
	B loop

shifter_left:
	MOV r0, r0, lsl #1
	STR r0, [r1]
	MOV r3, lr              @Save lr for not lost the reference
	BL delay                @delay, will be linked here
	MOV pc, r3              @Return

shifter_right:
	MOV r0, r0, lsr #1
	STR r0, [r1]
	MOV r3, lr
	BL delay
	MOV pc, r3
	
.end
