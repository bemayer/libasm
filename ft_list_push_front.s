global		ft_list_push_front
extern		malloc

ft_list_push_front:
	mov		rax, rdi
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
	mov		[rax], rsi
	mov		rcx, [rdi]
	mov		[rax+8], rcx
	mov		[rdi], rax
	mov		rax, rdi
.end:
	ret
