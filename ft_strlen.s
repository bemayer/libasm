global		ft_strlen

ft_strlen:
	mov		rax, 0

.beg:
	cmp		BYTE [rdi], 0
	jz		.end
	inc		rax
	inc		rdi
	jmp		.beg

.end:
	ret
