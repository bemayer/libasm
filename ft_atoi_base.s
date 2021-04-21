global		ft_atoi_base

; global		_start

; section .data
; string:
; 	db '7FFFFFFF', 0

; base:
; 	db '0123456789ABCDEF', 0

; section .text
; _start:
; 	mov		rdi, string
; 	mov		rsi, base
; 	call	ft_atoi_base
; 	xor rdi, rdi
; 	mov rax, 60
; 	syscall

ft_atoi_base:
	xor		rax, rax
	push	r12

.check_base:
	cmp		rsi, 0
	je		.end
	xor		r8, r8
.cb1:
	movzx	r10, BYTE [rsi + r8]
	cmp		r10, 0
	je		.cb4
	cmp		r10, 32
	je		.end
	cmp		r10, 43
	je		.end
	cmp		r10, 45
	je		.end
	sub		r10, 8
	cmp		r10, 6
	jb		.end
	add		r10, 8
	mov		r9, r8
.cb2:
	inc		r9
	movzx	r11, BYTE [rsi + r9]
	cmp		r11, 0
	je		.cb3
	cmp		r11, r10
	je		.end
	inc		r9
	jmp		.cb2
.cb3:
	inc		r8
	jmp		.cb1
.cb4:
	cmp		r8, 2
	jb		.end

.skip_ws:
	xor		r10, r10
.sw1:
	movzx	r9, BYTE [rdi + r10]
	cmp		r9, 32
	je		.sw2
	sub		r9, 8
	cmp		r9, 6
	jb		.sw2
	add		r9, 8
	jmp		.check_sign
.sw2:
	add		r9, 8
	inc		r10
	jmp		.sw1

.check_sign:
	xor		r11, r11
.cs1:
	cmp		r9, 43
	je		.cs3
	cmp		r9, 45
	jne		.convert
	cmp		r11, 1
	je		.cs2
	inc		r11
	jmp		.cs3
.cs2:
	xor		r11, r11
.cs3:
	inc		r10
	movzx	r9, BYTE [rdi + r10]
	jmp		.cs1

.convert:
	mov		r12, 1
.cv1:
	cmp		r9, 0
	je		.cv4
	xor		rcx, rcx
.cv2:
	movzx	rdx, BYTE [rsi + rcx]
	cmp		rdx, 0
	je		.cv4
	cmp		r9, rdx
	je		.cv3
	inc		rcx
	jmp		.cv2
.cv3:
	imul	rax, r8
	add		rax, rcx
	inc		r10
	movzx	r9, BYTE [rdi + r10]
	jmp		.cv1
.cv4:
	cmp		r11, 0
	je		.end
	imul	rax, -1
	jmp		.end

.err:
	xor		rax, rax

.end:
	pop		r12
	ret
