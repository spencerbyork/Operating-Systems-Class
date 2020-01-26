.code32

.globl	strlen1             
strlen1:                              
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	8(%ebp), %ecx
	movsbl	(%ecx), %ecx
	cmpl	$0, %ecx
	movl	%eax, -8(%ebp)        
	jne	LBB0_2
	movl	$0, -4(%ebp)
	jmp	LBB0_3
LBB0_2:
	movl	8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	calll	strlen1
	addl	$1, %eax
	movl	%eax, -4(%ebp)
LBB0_3:
	movl	-4(%ebp), %eax
	addl	$24, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                    
.globl	strlen2
strlen2:                              
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	$0, -4(%ebp)
	movl	%eax, -8(%ebp)          
LBB1_1:                               
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ecx
	movsbl	(%eax,%ecx), %eax
	cmpl	$0, %eax
	je	LBB1_3
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	LBB1_1
LBB1_3:
	movl	-4(%ebp), %eax
	addl	$8, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                        
.globl	strlen3               
strlen3:                             
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, -4(%ebp)
	movl	%eax, -8(%ebp)          
LBB2_1:                                
	movl	-4(%ebp), %eax
	movsbl	(%eax), %eax
	cmpl	$0, %eax
	je	LBB2_3
	movl	-4(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)
	jmp	LBB2_1
LBB2_3:
	movl	-4(%ebp), %eax
	movl	8(%ebp), %ecx
	subl	%ecx, %eax
	addl	$8, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                       

