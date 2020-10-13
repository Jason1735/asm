# fibonacci.s - An example of using XADD to generate fibonacci sequence.
# notice: __cdecl printf may change the value of eax, ecx, edx.
.section .data
format:
	.asciz "%d\n"
item:
	.int 10

.section .text
.globl _start
_start:
	movl item, %ebx
	dec %ebx
	movl $1, %esi
	movl %esi, %edi
	pushl %esi
	pushl $format
	call printf
	addl $8, %esp
LC0:
	pushl %edi
	pushl $format
	call printf
	addl $8, %esp

	xaddl %esi, %edi
	dec %ebx
	jne LC0	
	
	movl $1, %eax
	int $0x80

