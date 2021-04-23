global		ft_read
extern		__errno_location

ft_read:
	mov		rax, 0
	cmp		rdx, 0
	jl		.end
	syscall
	cmp		rax, 0
	jl		.err
	jmp		.end

.err:
	neg		rax
	push		rax
	call	__errno_location wrt ..plt
	pop		rdi
	mov		[rax], rdi
	mov		rax, -1

.end:
	ret
