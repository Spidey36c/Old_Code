/* James Nordquist, 10/25/18
   Lab 8 Hex Dump
*/
#include <p32xxxx.h>
    .global main
.set noreorder

.data
Lwrlimit: .asciiz "0xa9D0001e5"
Uprlimit: .asciiz "0x9d000300"
Info1:    .asciiz "Address    F  E  D  C   B  A  9  8   7  6  5  4   3  2  1  0"
Info2:	  .asciiz "========  ===========  ===========  ===========  ==========="
CrLf:     .asciiz "\n\r"
Storestr: .space 14 //to hold the 8 hex digits and spaces inbetween them and at the end
    .align 2
.text
.ent main
main:
    addiu sp, sp, -20
    sw ra, 16(sp)
    sw fp, 12(sp)
    sw s2, 8(sp) //to hold current address
    sw s1, 4(sp) //to hold upper limit of address
    sw s0, 0(sp) //to hold lower limit of address
    addu fp, sp, $0
     // configure Uart1 for TX
     li   t0, 0x8000
     sw   t0, U1MODESET // Turn UART1 ON
     li   t0, 0x1400
     sw   t0, U1STASET  // Enable Receive and Transmit
    // done configuring UART1\
    
    la a0, Lwrlimit
    jal asciihex_to_bin
    nop
    or s0, v0, $0
    andi t0, s0, 0x0F
    beq t0, $0, loadupr
    nop
    srl s0, s0, 4
    sll s0, s0, 4
loadupr:
    la a0,Uprlimit
    jal asciihex_to_bin
    nop
    or s1, v0, $0
    andi t0, s1, 0x0F
    srl s1, s1, 4
    sll s1, s1, 4
    addiu s1, s1, 0x10
displaymemory:
    la a0, Info1
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
    la a0, Info2
    jal output_string
    nop
    la a0, CrLf
    jal output_string
    nop
outerloop:
    or s2, s0, $0
    or a0, s2, $0
    ori a1, $0, 0
    la a2, Storestr
    jal bin_to_asciihex
    nop
    la a0, Storestr
    jal output_string
    nop
    addiu s2, s2, 0x10
innerloop:
    addiu s2, s2, -4
    lw a0, 0(s2)
    ori a1, $0, 1
    la a2, Storestr
    jal bin_to_asciihex
    nop
    la a0, Storestr
    jal output_string
    nop
    andi t0, s2, 0x0F
    bne t0, $0, innerloop
    nop
dowhile:
    la a0, CrLf
    jal output_string
    nop
    addiu s0, s0, 0x10
    blt s0, s1, outerloop
    nop
release:
    lw ra, 16(sp)
    lw fp, 12(sp)
    lw s2, 8(sp) //to hold current address
    lw s1, 4(sp) //to hold upper limit of address
    lw s0, 0(sp) //to hold lower limit of address
    addiu sp, sp, 20
    
    j .
    nop
.end main
    
.ent is_a_hex_digit
is_a_hex_digit:
    is_a_digit:
    li t1, 0x30
    li t0, 0x30
    addiu v0, $0, -1 // set v0 to -1 if a0 is not a digit no change needed
    blt a0, t0, end // if a0 is less than thirty jump to the end of 
    nop		    // subroutine
    li t0, 0x39	    // else check
    ble a0, t0, found_a_digit // if a0 is less or equal 
    nop		    // to thirty nine jump to found_a_digit
    andi a0, a0, 0xDF	    // else check if a0 is a hex digit
    li t1, 0x37	    
    li t0, 0x41
    blt a0, t0, end // if a0 is less than fourty one jump to the end of 
    nop		    // subroutine
    li t0, 0x46	    // else check
    bgt a0, t0, end // if a0 is greater than 
    nop		    // fourty six jump to the end
		    // else drop to found a digit
found_a_digit:
    subu v0, a0, t1 // subtract t1 from a0 to make it a number hex and not a 
		    // character
end:
    jr ra //return
    nop
.end is_a_hex_digit
    
.ent asciihex_to_bin
// Stack Frame
//===Reg Save area===
// ra      12
// old fp  8
// s1      4
// s0	   0
asciihex_to_bin://take what was in a0 and turn it into its binary counterpart
		//and only the last 8 hex digits
    addiu sp, sp, -16
    sw ra, 12(sp)
    sw fp, 8(sp)
    sw s1, 4(sp) //address passed in a0
    sw s0, 0(sp) //live value to be returned in v0
    addu fp, sp, $0 //set frame pointer
    or s1, a0, $0 //set s1 to address passed in a0, so we can use a0 for is_a_digit
    or s0, $0, $0 //set s0 to zero so that if s0 had a value before the function call, this will clear it out
    lbu a0, 0(s1)
    blez a0, finishhex
    nop		//if the string passed has nothing in it, jump to end
    jal is_a_hex_digit
    nop		//get the first character of string
    bltz v0, loop3 //if the character was not a digit branch to loop3
    nop		//else add result to s0
    addu s0, v0, s0
loop3://get current character being pointed at and check if it is either
      //the end of the string or a digit
    addiu s1, s1 ,1 //point to next character
    lbu a0, 0(s1) //get character
    blez a0, finishhex //if it is a null jump to the end
    nop		//else check if it is a digit
    jal is_a_hex_digit
    nop
    bltz v0, loop3 //if v0 is a digit drop to horners method
    nop	    //else set start loop again
isadigit://apply horners method
    sll s0, s0, 4
    addu s0, s0, v0 //add result 
    j loop3
    nop
finishhex://restore and release stack
	//put result of changing string to binary in v0
    or v0, s0, $0
    lw ra, 12(sp)
    lw fp, 8(sp)
    lw s1, 4(sp) 
    lw s0, 0(sp) //restore
    addiu sp, sp, 16 //release space
    jr ra
    nop
.end asciihex_to_bin
    
.ent bin_to_asciihex
bin_to_asciihex: 
    li t3, 20 // 20 is ascii space
    li t1, 0 //counter for digits
while:
    rotr a0, a0, -4
    andi t0, a0, 0x0F
    li t2, 10
    blt t0, t2, isless10
    nop
    addiu t0, t0, 0x37
    sb t0, 0(a2)
    addiu a2, a2, 1
    addiu t1, t1, 1
    li t2, 1
    beq a1, t2, spaces
    nop
    bne a1, t2, isover
    nop
isless10:
    addiu t0, t0, 0x30
    sb t0, 0(a2)
    addiu a2, a2, 1
    addiu t1, t1, 1
    li t2, 1
    bne a1, t2, isover
    nop
spaces:
    andi t2, t1, 1 //checks to see if counter is even
    bne t2, $0, isover
    nop
    sb t3, 0(a2)
    addiu a2, a2, 1
isover:
    li t2, 8
    bne t1, t2, while
    nop
finish:
    sb t3, 0(a2)
    addiu a2, a2, 1
    sb t3, 0(a2)
    addiu a2, a2, 1
    sb $0, 0(a2)
    jr ra
    nop
    
.end bin_to_asciihex
    
    
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