	.file	"temp.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "hello im child\0"
	.align 8
.LC1:
	.ascii "hello im parent with child of pid %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	call	fork
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rcx
	call	puts
	jmp	.L3
.L2:
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
.L3:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 9.3.0"
	.def	fork;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
