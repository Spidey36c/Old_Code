/* James Nordquist, 10/25/18
   Lab 8 Hex Dump
*/
#include <p32xxxx.h>
.global main
.set noreorder

.data
.text
.ent main
main:
     // configure Uart1 for TX
     li   t0, 0x8000
     sw   t0, U1MODESET // Turn UART1 ON
     li   t0, 0x1400
     sw   t0, U1STASET  // Enable Receive and Transmit
    // done configuring UART1
    
.end main
    
.ent is_a_hex_digit
is_a_hex_digit:
    is_a_digit:
    li t1, 0x30
    li t0, 0x30
    addiu v0, $0, -1 // set v0 to -1 if a0 is not a digit no change needed
    blt a0, t0, end // if a0 is less than thirty jump to the end of 
    nop		    // subroutine
    li t0, 0x39
    ble a0, t0, found_a_digit // if a0 is less or equal 
    nop		    // to thirty nine jump to found_a_digit
    li t1, 0x37
    li t0, 0x41
    blt a0, t0, end // if a0 is less than fourty one jump to the end of 
    nop		    // subroutine
    li t0, 0x46
    ble a0, t0, found_a_digit // if a0 is less or equal 
    nop		    // to fourty six jump to found_a_digit
    li t1, 0x57
    li t0, 0x61
    blt a0, t0, end // if a0 is less than sixty one jump to the end of 
    nop		    // subroutine
    li t0, 0x66
    bgt a0, t0, end // if a0 is greater than sixty six
    nop		    //jump to found_a_digit
    
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
asciihex_to_bin://take what was in a0 and turn it into binary
    addiu sp, sp, -20
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
    li t0, 16
    multu s0, t0 //mult by 16
    mflo s0
    addu s0, s0, v0 //add result 
    j loop3
    nop
finishhex://restore and release stack
	//put result of changing string to binary in a0
    or v0, s0, $0
    lw ra, 16(sp)
    lw fp, 12(sp)
    lw s2, 8(sp) 
    lw s1, 4(sp) 
    lw s0, 0(sp) //restore
    addiu sp, sp, 20 //release space
    jr ra
    nop
.end asciihex_to_bin