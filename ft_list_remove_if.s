global ft_list_remove_if

ft_list_remove_if:
	push	rbx	; begin list
	push	rbp	; previous
	push	r12 ; current
	push	r13 ; ref
	push 	r14 ; cmp
	push	r15 ; free
	mov		rbx, rdi
	mov		rbp, 0
	mov		r12, [rdi]
	mov		r13, rsi
	mov		r14, rdx
	mov		r15, rcx

.loop:
	cmp		r12, 0
	je		.end
	mov		rdi, QWORD [r12]
	mov		rsi, r13
	call	r14
	cmp		eax, 0
	je		.found
	mov		rbp, r12
	jmp		.next

.found:
	mov		rdx, QWORD [r12 + 8]
	cmp		rbp, 0
	jne		.remove

.shift:
	mov		QWORD [rbx], rdx
	jmp		.free

.remove:
	mov		QWORD [rbp + 8], rdx
	jmp		.free

.free:
	mov		rdi, QWORD [r12]
	call	r15
	jmp		.next

.next:
	mov		r12, QWORD [r12 + 8]
	jmp		.loop

.end:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		rbp
	pop		rbx
	ret
