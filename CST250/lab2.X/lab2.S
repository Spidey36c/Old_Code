/* James Nordquist, 10/4/18
   Lab 2 Multiplying by addition
   while (N>0)
   {
     if(x[i] != 0 || y[i] !=0)
     {
	if(x[i] < 0)
	{
	    x = 0-x;
	    y = 0-y;
	}
	while(x>0)
	{    
	    sum = sum + y[i];
	    x--;
	}
     }
     MAC_ACC = MAC_ACC + sum
     i++;
     N--;
   }
*/
#include <p32xxxx.h>
.global main
.set noreorder

.data
MAC_ACC: .word 0
sum: .word 0
.text
X:  .word  5, 0, 3, 10, 7
Y:  .word  6, 2, 8, 1,  2
N:  .word  5  // a count of the number of elements in the X and Y arrays
    .align 2  // need to make sure the data before the code does not
              // cause it to become un-aligned.
main:
    la t0, X	
    la t1, Y
    la t2, sum
    la t3, MAC_ACC
    la t7, N	// assign the addresses of the variables to regs
    lw t9, 0(t2)
    lw t4, 0(t3)
    lw t8, 0(t7) // load the contents of the variable to regs
    beq t8, $0, noinput // check if N = 0
loop:
    li t9, 0 // reset sum(t9) to zero
    lw t5, 0(t0) // load contents of x[i](t0) into reg 
    lw t6, 0(t1) // load contents of y[i](t1) into reg
    beq t5 , $0, Done // check if x[i] = 0
    nop
    beq t6, $0, Done // check if y[i] = 0
    nop
    bgtz t5, mult // check if x[i] > 0
    nop
    sub t5, $0, t5 // negate x[i]
    sub t6, $0, t6 // negate y[i]
mult:
    addu t9, t9, t6 // sum = sum + y[i]
    addiu t5, t5, -1 // decrement x[i] 
    bne t5, $0, mult // jump to mult if x[i] != 0
    nop
Done:
    addu t4, t4, t9 // put the sum into t4 to be stored later into MAC_ACC
    addiu t8, t8 , -1 // decrement N
    addiu t1, t1, 0x4
    addiu t0, t0, 0x4 // point to the next number in the arrays of x[] and y[]
    bgtz t8, loop // if N <= 0 store t4 into MAC_ACC else jump back to loop
    nop
noinput:
    sw t4, 0(t3)
    j .
    nop
  
    
/*
    1) What should be different about items declared with a .word directive 
     in the .text segment and those declared with a .word directive in the 
     .data segment?
    
     items in .data segment can be change while items in .word segment
     can't be change
     
     2)Why does it make sense that a .space directive should not be used in a
     .text segment?
     
     the .space command sets aside memory to be used by a variable
     but since it is in the .text segment, any of the space made can't be
     changed
     
*/
    