/*
TESTE PARA ACENDER O LED 1 E 2 RESPECTIVAMENTE
*/

#Incia o codigo na funcao main
_start:	.global _start
		b main

main:
#Configura o GPBCON
mov r0, #0x56000000
add r0, #0x10
#configura a saida para o led 1 e 2
mov r1, #0x1400	
str r1, [r0]

#Configura o GPBDAT
mov r0, #0x56000000
add r0, #0x14
#acende o led 1 e 2
mov r1, #0x9F
str r1, [r0]

mov r2, #0x1000000
add r2, #0x18000
add r2, #0x6A0

demora:
	subs r2, r2, #1
	bne demora

mov r1, #0xFF
str r1, [r0]

mov r2, #0x1000000
add r2, #0x18000
add r2, #0x6A0

demora2:
	subs r2, r2, #1
	bne demora2

b main	

.end

