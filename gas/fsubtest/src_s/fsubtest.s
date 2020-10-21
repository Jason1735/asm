# fsubtest,s - An example of using fsub
.section .data
value1:
	.float 10.0
value2:
	.float 2.0

.section .text
.globl _start
_start:
	nop
	finit
	flds value1
	flds value2
	fsubp

	fstps value1
	fstps value2
	movl $0, %ebx
	movl $1, %eax
	int $0x80
