.type iSqrt_asml, @function
.globl iSqrt_asml
.section .text
one:
	.float 1.0
iSqrt_asml:
	sqrtss %xmm0, %xmm1
	movss one, %xmm0
	divss %xmm1, %xmm0
	retq
