global _ft_strlen
section .text
_ft_strlen:
		mov rax, 0
	.next:
		cmp byte [rdi+rax], 0
		je .end
		inc rax
		jmp .next
	.end:
		ret
