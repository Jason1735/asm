# movtest3.s - An example of using indexed memory locations
.section .data
format:
	.asciz "The value is %d\n"
values:
	.int 11, 22, 33, 44, 55, 66, 77, 88, 99, 110
.section .text
.globl _start
_start:
	xor %edi, %edi
L1:
	pushl values(, %edi, 4)
	pushl $format
	call printf
	addl $8, %esp
	inc %edi
	cmp $10, %edi
	jb L1
exit:
	movl $0, %ebx
	movl $1, %eax
	int $0x80

