.section .init
.globl _start
_start:
  @Configure
  ldr r0, =0x20200000
  mov r1, #1
  lsl r1, #18
  str r1, [r0, #4]

  @turn on
  mov r1, #1
  lsl r1, #16
  str r1, [r0, #40]

loop$:
  b loop$

