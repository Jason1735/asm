# looptest.s - An example of the loop instruction
.section .data
output:
	.asciz "The value is %d\n"
.section .text
.globl _start
_start:
	movl $100, %ecx
	movl $0, %eax
L1:
	addl %ecx, %eax
	loop L1
	pushl %eax
	pushl $output
	call printf
	addl $8, %esp

	movl $0, %ebx
	movl $1, %eax
	int $0x80
