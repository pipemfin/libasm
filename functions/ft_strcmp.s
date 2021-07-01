global			_ft_strcmp
section			.text
_ft_strcmp:		mov rax, -1
COMPARE:		inc rax
				mov dl, byte [rdi + rax]
				cmp dl, byte [rsi + rax]
				jne DIFF
				cmp dl, 0
				jne COMPARE
RETURN_EQ:		xor rax, rax
				ret
DIFF:			cmp dl, byte [rsi + rax]
				ja	VARA
				mov rax, -1
RETURN:			ret
VARA:			mov rax, 1
				jmp RETURN

; int strcmp(const char *s1, const char *s2);
;RETURN VALUES
;     The strcmp() and strncmp() functions return an integer greater than, equal to, or less than 0,
;     according as the string s1 is greater than, equal to, or less than the string s2.  The compari-
;     son is done using unsigned characters, so that `\200' is greater than `\0'.