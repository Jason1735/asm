# bubble.s - An example of the XCHG instruction
.section .data
values:
	.int 105, 235, 61, 315, 134, 221, 53, 145, 117, 5
.section .text
.globl _start
_start:
	movl $9, %ecx
L_LOOP1:
	movl $values, %esi
	movl %ecx, %ebx
L_LOOP2:
	movl (%esi), %eax
	cmpl %eax, 4(%esi)
	jle L_NEXT
	xchg %eax, 4(%esi)
	movl %eax, (%esi)
L_NEXT:
	addl $4, %esi
	dec %ebx
	jnz L_LOOP2
	dec %ecx
	jnz L_LOOP1
END:
	movl $0, %ebx
	movl $1, %eax
	int $0x80
