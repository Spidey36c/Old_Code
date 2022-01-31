#include <p32xxxx.h>
.global main
.set noreorder

.data

.text
.ent main
main:	
    addiu v0, zero, -1 // put a -1 in v0, assuming a b will not be found
    la t2, mystr       // get the address of the string into t2
    addiu t0, t2, -1   // get the address of the string into t0 (one byte ahead)
loop:
    addiu t0, t0, 1    // point t0 at the next string element
    lbu t1, 0(t0)      // get the next element of the string
    beq t1, zero, done // at end of the string and didn't find a 'b'
    addiu t1, t1, -'b' // or -0x62 or 0xFF9E
    bne t1, zero, loop
    nop
                       // found a 'b'
    subu v0, t0, t2    // get its index
done:
    
.end main
    