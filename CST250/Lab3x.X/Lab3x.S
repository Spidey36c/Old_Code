/* James Nordquist 10/11/18
    Lab 3 basic subroutine
*/
/*
    int main()
    {
    char p[] = "asdas123asd309asd8";
    int count = 0;
    int sum = 0;
    int isadigit = 0;
    char *c = p;
    
    while(*c != 0)
    {
	isadigit = is_a_digit(c)
	if(isadigit != -1) // if the character was a digit;
	{
	    count++;	// increment counter
	    sum += isadigit;	// add digit to sum
	}
	c++; // point to next character
    }
    return 0
    }
     
    int is_a_digit(char c) 
    {
    if (c >= 0x30 && c <= 0x39) 
    {
       // return the binary value for ASCII character digit
          return (c - 0x30);  
    } 
     else return (-1);
}
     
*/
#include <p32xxxx.h>
.global main
.set noreorder

.data
dCount: .word 0
dSum: .word 0
mystr:.asciiz"/This1is2 a 3 most 4 excellent 5 test 6 string 7 for8 Lab 93.0:"
    .align 2
    
.text
.ent main 
main:
    addiu sp, sp, -16 // reserve space for live values
    sw ra, 12(sp)   // put contents onto stack
    sw s0, 8(sp)    // put contents onto stack
    sw s1, 4(sp)    // put contents onto stack
    sw s2, 0(sp)    // put contents onto stack
    
    la s0, mystr // initiallized pointer to str
    addiu s1, $0, 0 // initiallized count
    addiu s2, $0, 0 // initiallized sum
    lbu a0, 0(s0)    // passed current character
    beq a0, $0, finish // if there is nothing in mystr jump to the finish
    nop
loop: // checks if current character being pointed at is a digit, if so
      // increment count, add digit to sum
    jal is_a_digit // check if character is a digit
    nop
    li t0, -1
    beq v0, t0, next // check if v0 = -1
    nop
    addiu s1, s1, 1 // if a0 was a number increment counter
    addu s2, s2, v0 // if a0 was a number add the number to sum
next: // point to the next character of the array
    addiu s0, s0, 1 // point to next character
    lbu a0, 0(s0) // load current character
    bne a0, $0, loop // if a0 is not null jump to loop
    nop
finish: // store count and sum and then release space from stack
    sw s1, dCount // store count
    sw s2, dSum // store sum
    
    lw ra, 12(sp)   // take contents off of stack
    lw s0, 8(sp)      // take contents off of stack
    lw s1, 4(sp)     // take contents off of stack
    lw s2, 0(sp)    // take contents off of stack
    addiu sp, sp, 16 // release space
    
    j .
    nop
.end main
    
.ent is_a_digit
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
    
    