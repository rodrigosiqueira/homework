#Turn on the led
  .text
_start:	.global _start
  .global main
b main
main:

#GPBCON register address
mov r0, #0x56000000		
add r0, r0, #0x10       /*S3C2440 needs two bit for configure the output.  */
mov r2, #0x15400        /*...| 01 | 01 | 01 | 01 | 00 | 00 | 00 | 00 | 00 |*/
str r2, [r0]            /*...|GPB8|GPB7|GPB6|GPB5|GPB4|   ...   |GPB1|GPB0|*/

#GPBDAT register address
mov r1, #0x56000000
add r1, r1, #0x014      /*Configures bit 5 and 7*/
mov r3, #0x750          /*| 1 | 1 | 1 | 0 | 1 | 0 | 1 | 1 | 1 | 1 | 1 |*/
add r3, r3, #0xf        /*| 10| 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |*/
str r3, [r1]

mov pc, lr
.end
