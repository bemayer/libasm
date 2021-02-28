global		ft_strdup
extern		ft_strcpy
extern		ft_strlen
extern		malloc


ft_strdup:
	push	rdi
	call	ft_strlen wrt ..plt
	inc		rax
	mov		rdi, rax
	call	malloc wrt ..plt
	cmp		rax,0
	je		.end
	mov		rdi, rax
	pop		rsi
	call	ft_strcpy wrt ..plt

.end:
	ret
