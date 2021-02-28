global		ft_strcmp

ft_strcmp:
	mov		eax, 1
	mov		ecx, 1

.beg:
	movzx	eax, BYTE [rdi]
	movzx	ecx, BYTE [rsi]
	cmp		eax, 0
	je		.mid
	cmp		al, 0
	je		.mid
	sub		eax, ecx
	jne		.end
	inc		rdi
	inc		rsi
	jmp		.beg

.mid:
	sub		eax, ecx

.end:
	ret
