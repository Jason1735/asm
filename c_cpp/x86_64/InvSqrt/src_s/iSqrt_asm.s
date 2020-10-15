.section .text
xhalf:
	.float 0.5
threehalf:
	.float 1.5 
.globl iSqrt_asm
	#x = 12(%esp)
	#xhalf = 4(%esp)
	#threehalf = (%esp)
iSqrt_asm:
	movd %xmm0, %edx
	movss xhalf, %xmm1
	mulss %xmm0, %xmm1
	movss threehalf, %xmm0

	movl $0x5f3759df, %eax
	sarl %edx
	subl %edx, %eax
	movd %eax, %xmm2
	mulss %xmm2, %xmm1
	mulss %xmm2, %xmm1
	subss %xmm1, %xmm0
	mulss %xmm2, %xmm0
	
	retq
