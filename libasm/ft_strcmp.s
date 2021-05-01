global _ft_strcmp
section .text
_ft_strcmp:
		mov rax, 0
		push rcx
		mov rcx, 0
		push rbx
		mov rbx, 0
	loop:
		mov al, [rdi + rcx]
		mov bl, [rsi + rcx]
		cmp al, 0
		je end
		cmp bl, 0
		je end
		cmp bl, al
		jne end
		inc rcx
		jmp loop
	end:
		sub rax, rbx
		pop rcx
		pop rbx
		ret
