.section .text
.type iSqrt_asml, @function
.globl iSqrt_asml
	#x = 4(%esp)
iSqrt_asml:
	flds 4(%esp)
	fsqrt
	fld1
	fdivp
	ret
