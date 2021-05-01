global _ft_strcpy
section .text
_ft_strcpy:
		cmp rsi, 0
		je end
		push rcx
		push rdx
		mov rcx, 0
	loop:
		mov dl, byte [rsi + rcx]
		mov byte [rdi + rcx], dl
		cmp dl, 0
		je end
		inc rcx
		jmp loop
	end:
		mov rax, rdi
		pop rcx
		pop rdx
		ret

