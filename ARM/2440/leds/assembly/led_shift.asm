@Arquivo principal responsavel pela construcao 
@do codigo. Este arquivo sera linkado com o 
@arquivo delay
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
	@Configura o GPBCON
	MOV r0, #0x15400
	LDR r1, =GPBCON
	STR r0, [r1]

	@Apaga todos os leds
	LDR r2, =CST
	LDR r1, =GPBDAT
	STR r2, [r1]
	
loop:
	@Valor base para o deslocamento
	MOV r0, #0x7E0
	ADD r0, #0XF
	
	@Acende o led 5
	BL shifter_left
	
	@Acende o led 6
	BL shifter_left
	
	@Acende o led 7
	BL shifter_left

	@Acende o led 8
	BL shifter_left

	@Acende o led 7
	BL shifter_right

	@Acende o led 6
	BL shifter_right

	@Acende o led 5
	BL shifter_right
	
	B loop

shifter_left:
	MOV r0, r0, lsl #1
	STR r0, [r1]
	MOV r3, lr					@Para nao perder a referencia
	BL delay
	MOV pc, r3

shifter_right:
	MOV r0, r0, lsr #1
	STR r0, [r1]
	MOV r3, lr					@Para nao perder a referencia
	BL delay
	MOV pc, r3
	
.end
