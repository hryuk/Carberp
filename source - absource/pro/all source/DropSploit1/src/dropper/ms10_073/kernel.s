	.file	"kernel.cpp"
	.text
	.p2align 2,,3
.globl __Z13GetKernelBasev
	.def	__Z13GetKernelBasev;	.scl	2;	.type	32;	.endef
__Z13GetKernelBasev:
	pushl	%ebp
	movl	%esp, %ebp
/APP
 # 22 "kernel.cpp" 1
	movl $119,%eax
 # 0 "" 2
/NO_APP
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%08x %08x\0"
	.text
	.p2align 2,,3
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
/APP
 # 22 "kernel.cpp" 1
	movl $119,%eax
 # 0 "" 2
/NO_APP
	xorl	%eax, %eax
	movl	%eax, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	xorl	%eax, %eax
	leave
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
