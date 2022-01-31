#include <p32xxxx.h>
.global main
.set noreorder

.data

.text
.ent main
main:	
    li a0, 5
    li a1, 5
mulsub:
    beq  a0, $0, muldone //if a0 or a1 is 0
    addu v0, $0, $0 //initialize v0 to 0 Always useful
    beq  a1, $0, muldone //skip the loop
mulloop:
    addu v0, v0, a0 //add a0 to v0 a1 times Only useful if                 //branch not is taken
    bne  a1, $0 + 1, mulloop
    addiu a1, a1, -1
muldone:
    j .         //return
    nop 

    
.end main
    
    
