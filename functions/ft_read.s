global		_ft_read
extern		___error
section		.text
_ft_read:	mov rax, 0x2000003

			syscall
			jc ERR
RETURN:		ret
ERR:		push rax
			call ___error
			pop rdi
			mov [rax], rdi
			mov rax, -1
			jmp RETURN