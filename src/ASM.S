#include "avr/io.h"
.global btnReadD12
.global digitalSetASM
.global digitalClearASM
.global UartTransmit

btnReadD12:
  push r16
  in r16,0x03
  andi r16,0x10
  breq writeZero
  
writeOne:
  ldi r24,0x01
  pop r16
  ret

writeZero:
  ldi r24,0x00
  pop r16
  ret

digitalSetASM: 
  push r0
  push r1
  adiw r24,0x20
  clr XH
  mov XL,r24

writeOneSet:
  ld r20,X
  or r20,r22
  st X,r20
  pop r1
  pop r0
  ret


digitalClearASM:
  push r0
  push r1
  adiw r24,0x20
  clr XH
  mov XL,r24
writeZeroSet:
  ld r20,X
  com r22
  and r20,r22
  st X,r20
  pop r1
  pop r0
  ret


UartTransmit:
    
    push r18
    uart:
    lds r18,0xC0
    sbrs r18,0x05
    rjmp uart
    sts 0xC6, r24
    pop r18
    ret




