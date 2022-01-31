/* James Nordquist, 10/25/18
   Lab 5 Stack Frame
*/
#include <p32xxxx.h>
.global main
.set noreorder

.data
Numof:    .asciiz "The number of _s is: "
Totalof:  .asciiz "The total number of digits is: "
CrLf:     .asciiz "\n\r"
Mystr:	  .asciiz ""
Numstr:   .space 11   // space for up to 10 ascii digit characters and a null
    .align 2
.text
.ent main
// Stack Frame
//===Reg Save area===
// ra      72
// old fp  68
// s0      64
// s1      60
//====Local Vars=====
// total_count 56
// var_count array 52-16
//==Parameter space==
// res a3  12
// res a2 8
// res a1 4
// res a0 0
main:
    #define total_count 56
    #define var_count 16    //Easier to access stack fram
    addiu sp, sp, -76
    sw ra, 72(sp)
    sw fp, 68(sp)
    sw s0, 64(sp) //used for accessing var_count and total count
    sw s1, 60(sp) //used as a pointer to string to be checked and counter for 
		  //var_count
    addu fp, $0, sp //assign frame pointer to same address as stack pointer
    addiu t1, fp, var_count
    addiu t2, fp, total_count
zero1: //set all the var_count to 0
    li t0, 0
    sw t0, 0(t1) //store 0 in current var_count
    addiu t1, t1, 4
    blt t1, t2, zero1 //if we not are done setting all var_count to 0
    nop		     //start over
    // configure Uart1 for TX
     li   t0, 0x8000
     sw   t0, U1MODESET // Turn UART1 ON
     li   t0, 0x1400
     sw   t0, U1STASET  // Enable Receive and Transmit
    // done configuring UART1

    la s1, Mystr //String to be checked
    li s0, 0 //total_count
    lbu a0, 0(s1)
    beq a0, $0, check1 //check to see if s0 has nothing in it
    nop
loop1: //Read string and see if it has any digits and increment total_count
       //And the relative var_count
    jal is_a_digit
    nop
    bltz v0, check1 //is the is_a_digit return a digit, or a character
    nop
    addiu s0, s0, 1 //if it was a digit add one to total_count
    sw s0, total_count(fp)
    // accessing and incrementing var_count[i] with i in v0  
    addiu t0, fp, var_count // t0 gets the address of the base of the 
			    //variable array
    sll   v0, v0, 2  // multiply the index by 4 (4 bytes per word)
    addu  t0, t0, v0 // t0 gets the address of the indexed element
    lw    v0, 0(t0)  // get the element
    addiu v0, v0, 1  // increment it
    sw    v0, 0(t0)  // and put it back
check1://see if we hit the end of the string in s1
    addiu s1, s1, 1 //point to next character
    lbu a0, 0(s1)
    bne a0, $0, loop1 //is a0 a null
    nop
    addiu s0, fp, var_count //if a0 is null look at the first var_count
    li s1, 0x30 //ascii zero to replace _ in Numof
loop2: //replace the _ with the relative digit and output the total number
       //of specific digits using var_count
    la a0, Numof
    addiu a0, a0, 14 //point to _
    sb s1, 0(a0) //replace _
    la a0, Numof //back to the beginning
    jal output_string
    nop
    lw a0, 0(s0) //number of specific digits in MyStr
    la a1, Numstr
    jal bin_to_ascii
    nop
    la a0, Numstr //ascii version of current var_count
    jal output_string
    nop
    la a0, CrLf //newline
    jal output_string
    nop
    addiu s1, s1, 1 //next ascii character
    addiu s0, s0, 4 //next var_count
    addiu t0, fp, total_count
    blt s0, t0, loop2 //if s0 is less than total_count on the stack
    nop		      //jump to loop
release: //output the total count of digits in Mystr and release the
	 //space we used on the stack
    la a0, CrLf //Newline
    jal output_string
    nop
    la a0, Totalof
    jal output_string
    nop
    lw a0, total_count(fp) //total number of digits in Mystr
    la a1, Numstr
    jal bin_to_ascii
    nop
    la a0, Numstr //output total number of digits in Mystr
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
    
    lw s1, 60(sp)
    lw s0, 64(sp)
    lw fp, 68(sp)
    lw ra, 72(sp) //restore
    addiu sp, sp, 76 //release
    
    j .
    nop
.end main


.ent is_a_digit
/*
    is_a_digit
    passed a byte from a string in a0
     
    this function checks if a0 is an ascii digit, and if it is
    subtracts 30 from it and places it into v0
     
    this function returns a digit in v0
*/
is_a_digit:
    li t0, 0x39
    addiu v0, $0, -1 // set v0 to -1 if a0 is not a digit no change needed
    bgt a0, t0, end // if a0 is greater than thirty nine jump to the end of 
    nop		    // subroutine
    li t0, 0x30
    blt a0, t0, end // if a0 is less than thirty jump to the end of subroutine
    nop		    
    subu v0, a0, t0 // subtract 30 from a0 to make it a number and not a 
		    // character
end:
    jr ra //return
    nop
.end is_a_digit
    
  
.ent bin_to_ascii
/*
   bin_to_ascii
   passed a digit in a0, and pointer to beginning of address in a1
    
   this function takes what digit is in a0 and stores it revserse
   order as an character in a1, then correctly orders a1
     
   this function returns nothing as what we are modifying is a 
   character array
*/  
bin_to_ascii: //Take what is in a0 and turn it into ascii
    li t0, 10 //Number to be divided by
    addu t2, $0, a1 //Load the address of the first character in array
while: //Divide a0 by 10 and turn remainder into ascii
    divu $0, a0, t0 //Divide
    mfhi t1 //Put remainder into t1
    mflo a0 //Put quotient into a0
    addiu t1, t1, 0x30 //Turn the digit in t1 into ascii
    sb t1, 0(a1) //Store character into a1
    addiu a1, a1, 1 //Next character in string
    bne a0, $0, while //If a0 is not 0, continue loop
    nop
finish: //Terminate character string, get ready to fix character positions
    sb $0, 0(a1) //Terminate string in null
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