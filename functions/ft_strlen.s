global		_ft_strlen
section		.text
_ft_strlen:	xor rax, rax
COUNT:		cmp byte [rdi + rax], 0
			je RETURN
			inc rax
			jmp COUNT
RETURN:		ret