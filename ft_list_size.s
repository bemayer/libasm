global		ft_list_size

ft_list_size:
	xor		rax, rax

.loop:
	cmp		rdi, 0
	je		.end
	mov		rdi, QWORD [rdi + 8]
	inc		rax
	jmp		.loop

.end:
	ret
