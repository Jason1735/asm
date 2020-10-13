# cmovtest.s - An example of CMOV instructions
# The program finds the largest integer in a series defined in the values array.
# Return by sys_exit, so the largest should be less than 0xFF. 
.section .data
values:
	.int 99, 76, 123, 11, 33, 81, 59, 222, 91, 255, 123, 45

.section .text
.globl _start
_start:
	movl values, %ebx
	movl $1, %edi
	movl $12, %ecx
L1:
	movl values(, %edi, 4), %edx
	cmp %ebx, %edx
	cmovge %edx, %ebx
	inc %edi
	loop L1

	movl $1, %eax
	int $0x80
