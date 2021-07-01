global		_ft_strcpy
section		.text
_ft_strcpy:	xor rax, rax
COPY:		mov cl, byte [rsi + rax]
			mov byte [rdi + rax], cl
			cmp byte [rsi + rax], 0
			je RETURN
			inc rax
			jmp COPY
RETURN:		mov rax, rdi
			ret