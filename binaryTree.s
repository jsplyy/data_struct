	.file	"binaryTree.c"
	.text
	.globl	__Z9InitQueueP12queue_struct
	.def	__Z9InitQueueP12queue_struct;	.scl	2;	.type	32;	.endef
__Z9InitQueueP12queue_struct:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	$0, 40(%eax)
	movl	8(%ebp), %eax
	movl	$0, 44(%eax)
	popl	%ebp
	ret
	.globl	__Z10queue_pushP12queue_structP11binary_tree
	.def	__Z10queue_pushP12queue_structP11binary_tree;	.scl	2;	.type	32;	.endef
__Z10queue_pushP12queue_structP11binary_tree:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	44(%eax), %eax
	cmpl	$9, %eax
	jg	L2
	movl	8(%ebp), %eax
	movl	44(%eax), %edx
	movl	8(%ebp), %eax
	movl	12(%ebp), %ecx
	movl	%ecx, (%eax,%edx,4)
	movl	8(%ebp), %eax
	movl	44(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 44(%eax)
L2:
	popl	%ebp
	ret
	.globl	__Z9queue_popP12queue_struct
	.def	__Z9queue_popP12queue_struct;	.scl	2;	.type	32;	.endef
__Z9queue_popP12queue_struct:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	40(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	40(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 40(%eax)
	movl	-4(%ebp), %eax
	leave
	ret
	.globl	__Z10queueEmptyP12queue_struct
	.def	__Z10queueEmptyP12queue_struct;	.scl	2;	.type	32;	.endef
__Z10queueEmptyP12queue_struct:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	44(%eax), %edx
	movl	8(%ebp), %eax
	movl	40(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	testl	%eax, %eax
	jg	L7
	movl	$1, %eax
	jmp	L8
L7:
	movl	$0, %eax
L8:
	popl	%ebp
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "bt1->data=%d\11\0"
LC1:
	.ascii "bt2->data=%d\11\0"
LC2:
	.ascii "bt3->data=%d\11\0"
LC3:
	.ascii "\12PreOrderTraverse:\0"
LC4:
	.ascii "\12InOrderTraverse:\0"
LC5:
	.ascii "\12PostOrderTraverse:\0"
LC6:
	.ascii "\12LevelOrderTraverse:\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$96, %esp
	call	___main
	movl	$1, 84(%esp)
	leal	72(%esp), %eax
	movl	%eax, 88(%esp)
	leal	60(%esp), %eax
	movl	%eax, 92(%esp)
	movl	$2, 72(%esp)
	leal	48(%esp), %eax
	movl	%eax, 76(%esp)
	leal	36(%esp), %eax
	movl	%eax, 80(%esp)
	movl	$3, 60(%esp)
	leal	24(%esp), %eax
	movl	%eax, 64(%esp)
	movl	$0, 68(%esp)
	movl	$4, 48(%esp)
	movl	$0, 52(%esp)
	movl	$0, 56(%esp)
	movl	$5, 36(%esp)
	movl	$0, 40(%esp)
	movl	$0, 44(%esp)
	movl	$6, 24(%esp)
	movl	$0, 28(%esp)
	movl	$0, 32(%esp)
	movl	84(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	88(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	92(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$LC3, (%esp)
	call	_printf
	leal	84(%esp), %eax
	movl	%eax, (%esp)
	call	__Z16PreOrderTraverseP11binary_tree
	movl	$LC4, (%esp)
	call	_printf
	leal	84(%esp), %eax
	movl	%eax, (%esp)
	call	__Z15InOrderTraverseP11binary_tree
	movl	$LC5, (%esp)
	call	_printf
	leal	84(%esp), %eax
	movl	%eax, (%esp)
	call	__Z17PostOrderTraverseP11binary_tree
	movl	$LC6, (%esp)
	call	_printf
	leal	84(%esp), %eax
	movl	%eax, (%esp)
	call	__Z18levelOrderTraverseP11binary_tree
	movl	$0, %eax
	leave
	ret
	.section .rdata,"dr"
LC7:
	.ascii "%d \0"
	.text
	.globl	__Z16PreOrderTraverseP11binary_tree
	.def	__Z16PreOrderTraverseP11binary_tree;	.scl	2;	.type	32;	.endef
__Z16PreOrderTraverseP11binary_tree:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L12
	jmp	L11
L12:
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__Z16PreOrderTraverseP11binary_tree
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z16PreOrderTraverseP11binary_tree
L11:
	leave
	ret
	.globl	__Z15InOrderTraverseP11binary_tree
	.def	__Z15InOrderTraverseP11binary_tree;	.scl	2;	.type	32;	.endef
__Z15InOrderTraverseP11binary_tree:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L15
	jmp	L14
L15:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__Z15InOrderTraverseP11binary_tree
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z15InOrderTraverseP11binary_tree
L14:
	leave
	ret
	.globl	__Z17PostOrderTraverseP11binary_tree
	.def	__Z17PostOrderTraverseP11binary_tree;	.scl	2;	.type	32;	.endef
__Z17PostOrderTraverseP11binary_tree:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L18
	jmp	L17
L18:
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__Z17PostOrderTraverseP11binary_tree
	movl	8(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, (%esp)
	call	__Z17PostOrderTraverseP11binary_tree
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
L17:
	leave
	ret
	.globl	__Z18levelOrderTraverseP11binary_tree
	.def	__Z18levelOrderTraverseP11binary_tree;	.scl	2;	.type	32;	.endef
__Z18levelOrderTraverseP11binary_tree:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9InitQueueP12queue_struct
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10queue_pushP12queue_structP11binary_tree
	jmp	L21
L23:
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z9queue_popP12queue_struct
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	L22
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10queue_pushP12queue_structP11binary_tree
L22:
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	testl	%eax, %eax
	je	L21
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10queue_pushP12queue_structP11binary_tree
L21:
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z10queueEmptyP12queue_struct
	xorl	$1, %eax
	testb	%al, %al
	jne	L23
	leave
	ret
	.ident	"GCC: (tdm-1) 4.9.2"
	.def	_printf;	.scl	2;	.type	32;	.endef
