#cpuid.s Sample program to extract the processor Vendor ID
.section .data
	output: .ascii "The processor Vendor ID is 'xxxxxxxxxxxx'\n"
	len = . - output

.section .text
.globl _start

_start:
	movl $0, %eax
	cpuid
	movl $output, %edi
	movl %ebx, 28(%edi)
	movl %edx, 32(%edi)
	movl %ecx, 36(%edi)

	movl $len, %edx
	movl %edi, %ecx
	movl $1, %ebx
	movl $4, %eax
	int $0x80

	movl $0, %ebx
	movl $1, %eax
	int $0x80
	
