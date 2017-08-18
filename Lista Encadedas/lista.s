	.file	"lista.c"
	.globl	contador
	.data
	.align 4
	.type	contador, @object
	.size	contador, 4
contador:
	.long	1
	.section	.rodata
.LC0:
	.string	"---Aluno adicionado!---"
	.text
	.globl	insert
	.type	insert, @function
insert:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	$72, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy
	movl	contador(%rip), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 52(%rax)
	movq	-8(%rbp), %rax
	movl	-36(%rbp), %edx
	movl	%edx, 56(%rax)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 64(%rax)
	movl	$.LC0, %edi
	call	puts
	movl	contador(%rip), %eax
	addl	$1, %eax
	movl	%eax, contador(%rip)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	insert, .-insert
	.section	.rodata
.LC1:
	.string	"Aluno n\303\243o encontrado!\n"
.LC2:
	.string	"Aluno deletado!\n"
	.text
	.globl	deleta
	.type	deleta, @function
deleta:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	$0, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L4
.L6:
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, -8(%rbp)
.L4:
	cmpq	$0, -8(%rbp)
	je	.L5
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L6
.L5:
	cmpq	$0, -8(%rbp)
	jne	.L7
	movl	$.LC1, %edi
	call	puts
	movq	-24(%rbp), %rax
	jmp	.L8
.L7:
	cmpq	$0, -16(%rbp)
	jne	.L9
	movq	-8(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, -24(%rbp)
	movl	$.LC2, %edi
	call	puts
	jmp	.L10
.L9:
	movq	-8(%rbp), %rax
	movq	64(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 64(%rax)
	movl	$.LC2, %edi
	call	puts
.L10:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-24(%rbp), %rax
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	deleta, .-deleta
	.section	.rodata
.LC3:
	.string	"\n\n---FIM DA LISTA---"
.LC4:
	.string	"\nNome do Aluno: %s\n"
.LC5:
	.string	"Matricula:     %d\n"
.LC6:
	.string	"Media:         %d\n"
	.text
	.globl	print
	.type	print, @function
print:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L12
	movl	$.LC3, %edi
	call	puts
	jmp	.L14
.L12:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movl	52(%rax), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movl	56(%rax), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, %rdi
	call	print
.L14:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	print, .-print
	.section	.rodata
.LC7:
	.string	"\n-----------MENU------------"
.LC8:
	.string	"\n1- Adicionar Aluno;"
.LC9:
	.string	"2- Imprimir lista de alunos;"
.LC10:
	.string	"3- Buscar aluno;"
.LC11:
	.string	"4- Apagar aluno;"
.LC12:
	.string	"5- Apagar lista;"
.LC13:
	.string	"6 - Sair do programa;"
	.text
	.globl	printMenu
	.type	printMenu, @function
printMenu:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC7, %edi
	call	puts
	movl	$.LC8, %edi
	call	puts
	movl	$.LC9, %edi
	call	puts
	movl	$.LC10, %edi
	call	puts
	movl	$.LC11, %edi
	call	puts
	movl	$.LC12, %edi
	call	puts
	movl	$.LC13, %edi
	call	puts
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	printMenu, .-printMenu
	.section	.rodata
.LC14:
	.string	"\n\t1.1- Continuar;"
	.align 8
.LC15:
	.string	"\n\t1.2- Adicionar mais um aluno;"
	.text
	.globl	printMenu2
	.type	printMenu2, @function
printMenu2:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC14, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC15, %edi
	movl	$0, %eax
	call	printf
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	printMenu2, .-printMenu2
	.section	.rodata
.LC16:
	.string	"\t3.1- Buscar por nome;"
.LC17:
	.string	"\t3.2- Buscar por matricula;"
	.align 8
.LC18:
	.string	"\t3.3- Buscar alunos que passaram;"
	.text
	.globl	printMenu3
	.type	printMenu3, @function
printMenu3:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC16, %edi
	call	puts
	movl	$.LC17, %edi
	call	puts
	movl	$.LC18, %edi
	call	puts
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	printMenu3, .-printMenu3
	.section	.rodata
.LC19:
	.string	"\n\nAluno: %s\n"
.LC20:
	.string	"Matricula: %d\n"
.LC21:
	.string	"Media: %d\n"
.LC22:
	.string	"---Aluno n\303\243o encontrado!---"
	.text
	.globl	comparaNome
	.type	comparaNome, @function
comparaNome:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L19
.L21:
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L20
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC19, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movl	52(%rax), %eax
	movl	%eax, %esi
	movl	$.LC20, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movl	56(%rax), %eax
	movl	%eax, %esi
	movl	$.LC21, %edi
	movl	$0, %eax
	call	printf
	movl	$1, -4(%rbp)
.L20:
	movq	-24(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, -24(%rbp)
.L19:
	cmpq	$0, -24(%rbp)
	jne	.L21
	cmpl	$0, -4(%rbp)
	jne	.L23
	movl	$.LC22, %edi
	call	puts
.L23:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	comparaNome, .-comparaNome
	.section	.rodata
.LC23:
	.string	"\nAluno: %s\n"
.LC24:
	.string	"\n---Aluno nao encontrado!---"
	.text
	.globl	comparaMatricula
	.type	comparaMatricula, @function
comparaMatricula:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L25
.L27:
	movq	-24(%rbp), %rax
	movl	52(%rax), %eax
	cmpl	-28(%rbp), %eax
	jne	.L26
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC23, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movl	52(%rax), %eax
	movl	%eax, %esi
	movl	$.LC20, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movl	56(%rax), %eax
	movl	%eax, %esi
	movl	$.LC21, %edi
	movl	$0, %eax
	call	printf
	movl	$1, -4(%rbp)
.L26:
	movq	-24(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, -24(%rbp)
.L25:
	cmpq	$0, -24(%rbp)
	jne	.L27
	cmpl	$0, -4(%rbp)
	jne	.L29
	movl	$.LC24, %edi
	call	puts
.L29:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	comparaMatricula, .-comparaMatricula
	.section	.rodata
.LC25:
	.string	"\n---Nenhum aluno passou!---"
	.text
	.globl	comparaPassou
	.type	comparaPassou, @function
comparaPassou:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L31
.L33:
	movq	-24(%rbp), %rax
	movl	56(%rax), %eax
	cmpl	$6, %eax
	jle	.L32
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC23, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movl	52(%rax), %eax
	movl	%eax, %esi
	movl	$.LC20, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movl	56(%rax), %eax
	movl	%eax, %esi
	movl	$.LC21, %edi
	movl	$0, %eax
	call	printf
	movl	$1, -4(%rbp)
.L32:
	movq	-24(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, -24(%rbp)
.L31:
	cmpq	$0, -24(%rbp)
	jne	.L33
	cmpl	$0, -4(%rbp)
	jne	.L35
	movl	$.LC25, %edi
	call	puts
.L35:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	comparaPassou, .-comparaPassou
	.section	.rodata
.LC26:
	.string	"\nNome: "
.LC27:
	.string	"%s"
.LC28:
	.string	"Media: "
.LC29:
	.string	"%d"
	.text
	.globl	recebeDados
	.type	recebeDados, @function
recebeDados:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	%rdx, -24(%rbp)
	movl	$.LC26, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC27, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$.LC28, %edi
	movl	$0, %eax
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC29, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	insert
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	recebeDados, .-recebeDados
	.section	.rodata
	.align 8
.LC30:
	.string	"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nLISTA DE ALUNOS - ESTRUTURA DE DADOS"
.LC31:
	.string	"\nDigite uma opcao: "
.LC32:
	.string	"\n\tDigite a opcao 2: "
.LC33:
	.string	"\tDigite a segunda opcao: "
.LC34:
	.string	"Aluno: "
.LC35:
	.string	"\tMatricula: "
.LC36:
	.string	"Nome do aluno: "
.LC37:
	.string	"\n---PROGRAMA ENCERRADO---\n"
.LC38:
	.string	"Opcao invalida"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -136(%rbp)
	movl	$0, -152(%rbp)
	movl	$0, -148(%rbp)
	movl	$.LC30, %edi
	call	puts
	jmp	.L39
.L50:
	movl	$0, %eax
	call	printMenu
	movl	$.LC31, %edi
	movl	$0, %eax
	call	printf
	leaq	-152(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC29, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-152(%rbp), %eax
	cmpl	$1, %eax
	jne	.L40
	movq	-136(%rbp), %rdx
	movl	-140(%rbp), %ecx
	leaq	-128(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	recebeDados
	movq	%rax, -136(%rbp)
	movl	$0, %eax
	call	printMenu2
	movl	$.LC32, %edi
	movl	$0, %eax
	call	printf
	leaq	-148(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC29, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	jmp	.L41
.L42:
	movq	-136(%rbp), %rdx
	movl	-140(%rbp), %ecx
	leaq	-128(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	recebeDados
	movq	%rax, -136(%rbp)
	movl	$0, %eax
	call	printMenu2
	movl	$.LC32, %edi
	movl	$0, %eax
	call	printf
	leaq	-148(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC29, %edi
	movl	$0, %eax
	call	__isoc99_scanf
.L41:
	movl	-148(%rbp), %eax
	cmpl	$1, %eax
	jne	.L42
	jmp	.L39
.L40:
	movl	-152(%rbp), %eax
	cmpl	$2, %eax
	jne	.L43
	movq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	print
	jmp	.L39
.L43:
	movl	-152(%rbp), %eax
	cmpl	$3, %eax
	jne	.L44
	movl	$0, %eax
	call	printMenu3
	movl	$.LC33, %edi
	movl	$0, %eax
	call	printf
	leaq	-148(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC29, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-148(%rbp), %eax
	cmpl	$1, %eax
	jne	.L45
	movl	$.LC34, %edi
	movl	$0, %eax
	call	printf
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC27, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	leaq	-64(%rbp), %rdx
	movq	-136(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	comparaNome
.L45:
	movl	-148(%rbp), %eax
	cmpl	$2, %eax
	jne	.L46
	movl	$.LC35, %edi
	movl	$0, %eax
	call	printf
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC29, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-144(%rbp), %edx
	movq	-136(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	comparaMatricula
.L46:
	movl	-148(%rbp), %eax
	cmpl	$3, %eax
	jne	.L39
	movq	-136(%rbp), %rax
	movq	%rax, %rdi
	call	comparaPassou
	jmp	.L39
.L44:
	movl	-152(%rbp), %eax
	cmpl	$4, %eax
	jne	.L48
	movl	$.LC36, %edi
	movl	$0, %eax
	call	printf
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC27, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	leaq	-64(%rbp), %rdx
	movq	-136(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	deleta
	movq	%rax, -136(%rbp)
	jmp	.L39
.L48:
	movl	-152(%rbp), %eax
	cmpl	$5, %eax
	je	.L39
	movl	-152(%rbp), %eax
	cmpl	$6, %eax
	jne	.L49
	movl	$.LC37, %edi
	call	puts
	jmp	.L39
.L49:
	movl	$.LC38, %edi
	call	puts
.L39:
	movl	-152(%rbp), %eax
	cmpl	$6, %eax
	jne	.L50
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L52
	call	__stack_chk_fail
.L52:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
