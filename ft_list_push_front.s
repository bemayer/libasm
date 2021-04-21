global		ft_list_push_front
extern		malloc

ft_list_push_front:
	cmp		rdi, 0
	je		.end
	push	rdi
	push	rsi
	mov		rdi, 16
	call	malloc  wrt ..plt
	pop		rsi
	pop		rdi
	cmp		rax, 0
	je		.end
	mov		QWORD [rax], 0
	mov		[rax+8], rsi
	mov		rcx, [rdi]
	cmp		rcx, 0
	je		.end
	mov		[rax], rcx
.end:
	mov		[rdi], rax
	mov		rax, rdi
	ret
