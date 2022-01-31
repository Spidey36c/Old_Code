/* James Nordquist, 10/25/18
   Lab 6 Isqrt
*/
#include <p32xxxx.h>
.global main
.set noreorder

.data
DebugIter: .asciiz "debug iteration: "
Guess:    .asciiz " guess: "
Isqrtof:  .asciiz "The isqrt of "
Isqrtis:  .asciiz " is "
Check1:	  .asciiz " Check: "
Check2:	  .asciiz "^2 = "
Check3:	  .asciiz ", "
Check4:	  .asciiz "^2 = "
ErrorOne: .asciiz "There were more than 10 digits, or nothing in the string"
ErrorTwo: .asciiz "There were non-digit characters in the string"
CrLf:     .asciiz "\n\r"
Digstr:   .asciiz "253"
Numstr:   .space 11   // space for up to 10 ascii digit characters and a null
errno: .global
    .align 2
.text
// Stack Frame
//===Reg Save area===
// ra      28
// old fp  24
// s0      20
// s1      16
//==Parameter space==
// res a3  12
// res a2 8
// res a1 4
// res a0 0
.ent main
main:
    #define debug 1 //for debugging purposes
    addiu sp, sp, -32
    sw ra, 28(sp)
    sw fp, 24(sp)
    sw s1, 20(sp) //the result of isqrt
    sw s0, 16(sp) //number to be square rooted
    la t0, errno
    sw $0, 0(t0) //setting errno to 0 so if it was 0 it wont throw an error
		 //in a non error case
    // configure Uart1 for TX
     li   t0, 0x8000
     sw   t0, U1MODESET // Turn UART1 ON
     li   t0, 0x1400
     sw   t0, U1STASET  // Enable Receive and Transmit
    // done configuring UART1
    la a0, Digstr //String to be changed to binary
    jal ascii_to_bin
    nop
    or s0, v0, $0 //Digstr now binary and put into a0
    la t0, errno
    lw t0, 0(t0)
    blez t0, step2 //check if there was an error
    nop		   //if there was check what error it was
    li t1, 1
    beq t0, t1, error //was the error error 1?
    nop		      //if not load the message for error 2
    la a0, ErrorTwo
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
    j step2
    nop
error://if it was error 1 output the error message and jump to the end
    la a0, ErrorOne
    jal output_string //output error message
    nop
    la a0, CrLf
    jal output_string
    nop
    j theend
    nop
step2://if either error 2 or no error find the integer sqrt of s0
      //and store it in s1
    or a0, s0, $0 //put s0 into a0 to pass it to Isqrt
    jal Isqrt
    nop
    or s1, v0, $0 //put the result in s1
    la a0,Isqrtof
    jal output_string //output relevent info
    nop
    la a1, Numstr
    or a0, s0, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string //output relevent info
    nop
    la a0, Isqrtis
    jal output_string //output relevent info
    nop
    la a1, Numstr
    or a0, s1, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string //output relevent info
    nop
    la a0, Check1
    jal output_string //Check for correct sqrt
    nop
    or a0, s1, $0 //put isqrt result in a0
    la a1, Numstr
    jal bin_to_ascii //change it to ascii
    nop
    la a0, Numstr
    jal output_string //output
    nop
    la a0, Check2
    jal output_string
    nop
    multu s1, s1
    mflo a0
    la a1, Numstr
    jal bin_to_ascii //s1^2 into ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, Check3
    jal output_string
    nop
    or a0, s1, $0
    addiu a0, a0, 1 //s1+1
    la a1, Numstr
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, Check4
    jal output_string
    nop
    or a0, s1, $0
    addiu a0, a0, 1
    multu a0, a0
    mflo a0
    la a1, Numstr
    jal bin_to_ascii //s1+1^2 into ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
theend://release and restore stack
    lw ra, 28(sp)
    lw fp, 24(sp)
    lw s1, 20(sp)
    lw s0, 16(sp)
    addiu sp, sp, 32 //release and restore
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
   
/*
    ascii_to_bin
    passed a string in a0
     
    this function turns the string passed in a0 to binary
     
    this function returns digits in v0
*/
.ent ascii_to_bin
// Stack Frame
//===Reg Save area===
// ra      16
// old fp  12
// s2      8
// s1      4
// s0	   0
ascii_to_bin://take what was in a0 and turn it into binary
    addiu sp, sp, -20
    sw ra, 16(sp)
    sw fp, 12(sp)
    sw s2, 8(sp) //counter for number of digits
    sw s1, 4(sp) //address passed in a0
    sw s0, 0(sp) //live value to be returned in v0
    addu fp, sp, $0 //set frame pointer
    or s2, $0, $0 //set to 0
    or s1, a0, $0 //set s1 to address passed in a0, so we can use a0 for is_a_digit
    or s0, $0, $0 //set s0 to zero so that if s0 had a value before the function call, this will clear it out
    lbu a0, 0(s1)
    blez a0, error1
    nop		//if the string passed has nothing in it, jump to error 1
    jal is_a_digit
    nop		//get the first character of string
    bltz v0, loop3 //if the character was not a digit branch to loop3
    nop		//else add 1 to counter and add result to s0
    addiu s2, s2, 1
    addu s0, v0, s0
loop3://get current character being pointed at and check if it is either
      //the end of the string or a digit
    addiu s1, s1 ,1 //point to next character
    lbu a0, 0(s1) //get character
    blez a0, loopend //if it is a null jump to the end
    nop		//else check if it is a digit
    jal is_a_digit
    nop
    bgez v0, isadigit //if v0 is a digit jump to horners method
    nop	    //else set errno to 2nd error and start loop over again
    la t0, errno
    li t1, 2
    sw t1, 0(t0)
    j loop3
    nop
isadigit://apply horners method, increment counter, and check for error1
    addiu s2, s2, 1 //increment counter
    li t0, 10
    multu s0, t0 //mult by 10
    mflo s0
    addu s0, s0, v0 //add result 
    li t0, 11
    beq s2, t0, error1//if we have over ten digits branch to error1
    nop	    //else continue loop
    j loop3
    nop
 loopend://put result of changing string to binary in a0
    or v0, s0, $0
    j finishbin
    nop
error1: //if there was an error 1 place the current result into s0 and
    //place 1 into errno
    or v0, s0, $0
    la t0, errno
    li t1, 1
    sw t1, 0(t0)
finishbin://restore and release stack
    lw ra, 16(sp)
    lw fp, 12(sp)
    lw s2, 8(sp) 
    lw s1, 4(sp) 
    lw s0, 0(sp) //restore
    addiu sp, sp, 20 //release space
    jr ra
    nop
.end ascii_to_bin

/*
    Isqrt
    passed a0 as a 32 bit digit
     
    this function finds the integer sqrt of the passed digit
     
    this function returns  in v0
*/
.ent Isqrt
// Stack Frame
//===Reg Save area===
// ra      20
// old fp  16
// s3      12
// s2      8
// s1	   4
// s0	   0
Isqrt:
    addiu sp, sp, -24
    sw ra, 20(sp)
    sw fp, 16(sp)
    sw s3, 12(sp) //passed in 32-bit digit
    sw s2, 8(sp) //debug iterator
    sw s1, 4(sp) //prev_guess
    sw s0, 0(sp) //guess
    li t0, 1
    beq a0, t0, sqrtend //the sqrt of 1 is 1
    ori s0, $0, 1
    beq a0, $0, sqrtend //the sqrt of 0 is 0
    ori s0, $0, 0   //if a0 != 1 or 0 continue
    addiu s2, $0, 1 //assign debug iterator to 1
    or s3, $0, a0 //put the passed 32 bit digit in s3
    addu fp, sp, $0//set framepointer
    srl s0, s3, 1 //guess = n/2
    .if debug	//if debugging, the guesses
    la a0, DebugIter
    jal output_string
    nop
    la a1, Numstr
    or a0, s2, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, Guess
    jal output_string
    nop
    la a1, Numstr
    or a0, s0, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
    .endif
    addiu s2, s2, 1 //increment debug iterator
sqrt://find the isqrt of n
    or s1, s0, $0 //prev_guess = guess
    divu $0, s3, s1 // n/prev_guess
    mflo t0
    addu t0, s1, t0 //prev_guess + n/prev_guess
    srl s0, t0, 1 //guess = 1/2 (prev_guess + n/prev_guess)
    .if debug
    la a0, DebugIter
    jal output_string
    nop
    la a1, Numstr
    or a0, s2, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, Guess
    jal output_string
    nop
    la a1, Numstr
    or a0, s0, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
    .endif
    subu t0, s1, s0 //prev_guess - guess
    addiu s2, s2, 1 //increment debug iterator
    ori t1, $0, 1
    bgt t0, t1, sqrt //while prev_guess - guess > 1, loop
    nop
    multu s0, s0 //check to see if we need to subtract 1 from answer
    mflo t0
    blt t0, s3, sqrtend //if we have the right answer go to the end
    nop	    //else subtract 1 from answer
    addiu s0, s0, -1
    .if debug
    la a0, DebugIter
    jal output_string
    nop
    la a1, Numstr
    or a0, s2, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, Guess
    jal output_string
    nop
    la a1, Numstr
    or a0, s0, $0
    jal bin_to_ascii
    nop
    la a0, Numstr
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
    .endif
sqrtend://restore and release stack
    or v0, s0, $0 //place answer in v0
    lw ra, 20(sp)
    lw fp, 16(sp)
    lw s3, 12(sp) //passed in 32-bit digit
    lw s2, 8(sp) //debug iterator
    lw s1, 4(sp) //prev_guess
    lw s0, 0(sp) //guess
    addiu sp, sp, 24 //release
    jr ra
    nop
    
    
    
    
.end Isqrt