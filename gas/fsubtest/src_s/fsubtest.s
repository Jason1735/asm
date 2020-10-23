# fsubtest,s - An example of using fsub
# notice:
# fsubp <=> fsubp %st(0), %st(1) <=> st(1) = st(0) - st(1), pop st(0)
# fsub %st(0), %st(1) <=> st(1) = st(0) - st(1)
# fsub source <=> st(0) = st(0) - source
# fsubr source <=> st(0) = source - st(0)
.section .data
value1:
	.float 10.0
value2:
	.float 0.0

.section .text
.globl _start
_start:
	nop
	finit
	flds value1
	fsubr value2

	fstps value2
	movl $0, %ebx
	movl $1, %eax
	int $0x80
