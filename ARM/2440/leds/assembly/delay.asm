.section DELAY
.data
.set DELAY_DEC, 16877216

.text
.global delay
delay:
	LDR r4, =DELAY_DEC

atraso:
	SUBS r4, r4, #1
	BNE atraso

MOV pc, lr

.end
