# flo.s - An example of using x86_64 fpu
# notice: The first six integer or pointer arguments are passed in 
# registers RDI, RSI, RDX, RCX, R8, and R9, 
# while XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6 and XMM7 are used for 
# floating point arguments. 
# additional arguments are passed on the stack and 
# the return value is stored in RAX
.section .data
	values: .float 12.34, 13, 334.75, 17.8
	result: .double 0.0

	outstring: .asciz "Result is %f\n"
	
.section .text
.global _start
_start:
	leal values, %ebx
	flds 12(%ebx)
	flds 8(%ebx)
	flds 4(%ebx)
	flds (%ebx)

	fmulp
	faddp
	fdivp

	fstl result
	movq result, %xmm0
	movq $outstring, %rdi
	call printf
end:
	movq $0, %rdi
	call exit
