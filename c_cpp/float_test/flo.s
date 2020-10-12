.section .data
	values: .float 12.34, 13, 334.75, 17.8
	result: .double 0.0

	outstring: .asciz "Result is %f\n"
	
.section .text
.global main
main:
	leal values, %ebx
	flds 12(%ebx)
	flds 8(%ebx)
	flds 4(%ebx)
	flds (%ebx)

	fmulp
	faddp
	fdivp

	fstl result

	leal result, %ebx
	pushl 4(%ebx)
	pushl (%ebx)
	pushl $outstring
	call printf
end:
	pushl $0
	call exit
