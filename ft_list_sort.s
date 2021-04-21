global		ft_list_sort

ft_list_sort:
	push	r12 ; beg
	push	r13 ; previous
	push 	r14 ; current
	push	r15 ; ft_intcmp
	cmp		rdi, 0
	je		.end
	mov		r12, [rdi]
	mov		r15, rsi
	cmp		r15, 0
	je		.end
.start:
	mov		r13, r12
.loop:
	mov		r14, QWORD [r13]
	cmp		r14, 0
	je		.end
	mov		rdi, QWORD [r13 + 8]
	mov		rsi, QWORD [r14 + 8]
	call	r15
	cmp		eax, 0
	jg		.switch
	mov		r13, r14
	jmp		.loop
.switch:
	mov		rcx, QWORD [r13 + 8]
	mov		rdx, QWORD [r14 + 8]
	mov		QWORD [r14 + 8], rcx
	mov		QWORD [r13 + 8], rdx
	jmp		.start
.end:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	ret
