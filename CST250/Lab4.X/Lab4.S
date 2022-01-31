/* James Nordquist, 10/18/2018
   Lab 4 binary to Ascii Decimal
*/
#include <p32xxxx.h>
.global main
.set noreorder

.data
Numbers: .word 3456789876, 379, 0, 9, 103, 0xffffffff
N: .word 6
CrLf: .asciiz "\n\r"
ostr: .space 11
    .align 2
.text
.ent main
main:
    addiu sp, sp, -16 //reserve space
    sw ra, 12(sp) //Return address as we have subroutines
    sw s0, 8(sp) //Pointer at space
    sw s1, 4(sp) //How many elements of we have in an array
    sw s2, 0(sp) //Pointer at Numbers variable
    // configure Uart1 for TX
     li   t0, 0x8000
     sw   t0, U1MODESET // Turn UART1 ON
     li   t0, 0x1400
     sw   t0, U1STASET  // Enable Receive and Transmit
    // done configuring UART1
    la s0, ostr //Load address, s0 now a pointer at beginning of ostr
    la s1, N //Load address
    lw s1, 0(s1) //Load content of address, overwrites what is in s1
    la s2, Numbers-4 //Load the a byte behind address of Numbers
    blez s1, end //If there are no elements in array, stop
    nop
loop: //Take the decimal element of the array and 
      //make it ascii, then output it
    addiu s2, s2, 4 //Move a to next element in array
    la a1, ostr //Pointer at beginning
    lw a0, 0(s2) //Load content of array into s3
    jal bin_to_ascii //Change what is in a0 into ascii
    nop
    addu a0, $0, s0 //Make a0 point at the beginning of string
    jal output_string
    nop
    la a0, CrLf //Newline in output
    jal output_string
    nop
    addiu s1, s1, -1 //Subract -1 from N
    bne s1, $0, loop //If we are not out of elements to convert, 
    nop //repeat process 
end:
    lw ra, 12(sp) //Restore s registers used
    lw s0, 8(sp)
    lw s1, 4(sp)
    lw s2, 0(sp)
    addiu sp, sp, 16 //release space
    
    j .
    nop
    
    
.end main
    
    
/*
    bin_to_ascii
    passed a digit in a0, and pointer to beginning of address in a1
     
    this function takes what digit is in a0 and stores it revserse
    order as an character in a1, then correctly orders a1
     
    this function returns nothing as what we are modifying is a 
    character array
*/    
.ent bin_to_ascii
bin_to_ascii: //Take what is in a0 and turn it into ascii
    li t0, 10 //Number to be divided by
    la t2, ostr+10 //Pointer at end
while: //Divide a0 by 10 and turn remainder into ascii
    divu $0, a0, t0 //Divide
    mfhi t1 //Put remainder into t1
    mflo a0 //Put quotient into a0
    addiu t1, t1, 0x30 //Turn the digit in t1 into ascii
    sb t1, 0(a1) //Store character into a1
    addiu a1, a1, 1 //Next character in string
    beq a1, t2, finish //Is a1 at the end of its allotted space if it is
    nop	//Jump to finish
    bne a0, $0, while //If a0 is not 0, continue loop
    nop
finish: //Terminate character string, get ready to fix character positions
    sb $0, 0(a1) //Terminate string in null
    la t2, ostr //Load the address of the first character in array
    addu t3, a1, $0 //Load the address that a1 is pointing
    //(currently the null charecter) to into t3
    addiu t3, t3, -1 //Move to viable character
reverse: //Correctly order the string
    lbu t0, 0(t2) //load contents of what t2 is pointing at into t0
    lbu t1, 0(t3) //load contents of what t3 is pointing at into t1
    sb t0, 0(t3) //Store contents of what is in t0 into t3
    sb t1, 0(t2) //Store contents of what is in t0 into t3
    addiu t2, t2, 1 //Point at next character
    addiu t3, t3, -1 //Point at last character
    blt t2, t3, reverse // if we are not done ordering the string, loop again
    nop
    jr ra
    nop
.end bin_to_ascii
    
    
.ent output_string
output_string: // Sends a string to UART1
               // a pointer to the string to output is passed in a0
               // nothing is returned

     lbu   t0, 0(a0)      // get first char
     beq   t0, zero, done // if it is null, we are done
     nop


send:   
     sw    t0, U1TXREG    // send data to Uart1

wait_tx:
     lw    t0, U1STA          // get Uart1 Status  
     andi  t0, t0, 0x100      // select TX done bit
     beq   t0, zero, wait_tx  // if done bit not set, wait
     nop

     addiu a0, a0, 1      // update pointer to next char
     lbu   t0, 0(a0)      // get next char
     bne   t0, zero, send // if it is not null, output it
     nop

done:
    jr ra
    nop
.end output_string