.section .text
.type iSqrt_asm, @function
.globl iSqrt_asm
	#x = 12(%esp)
	#xhalf = 4(%esp)
	#threehalf = (%esp)
iSqrt_asm:
	subl $8, %esp
	
	movl $0x3f000000, 4(%esp)
	movl $0x3fc00000, (%esp)
	flds 4(%esp)
	fmul 12(%esp)
	
	movl $0x5f3759df, %eax
	movl 12(%esp), %edx
	sarl %edx
	subl %edx, %eax
	movl %eax, 12(%esp)
	fmul 12(%esp)
	fmul 12(%esp)
	flds (%esp)
	fsubp
	fmul 12(%esp)

	addl $8, %esp
	ret
