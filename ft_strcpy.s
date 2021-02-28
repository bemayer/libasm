global		ft_strcpy

ft_strcpy:
	mov		rax, rdi

.beg:
	cmp		BYTE [rsi], 0
	je		.end
	movsb
	jmp		.beg

.end:
	mov		BYTE [rdi], 0
	ret
