include irvine32.inc

.DATA
	multiplicand db 79h
	multiplier db 55h
	count db 7
	shcount = 8 - 7 + 8
	result dw ?

.CODE
main PROC
	mov edx, 0

	movzx ecx, count
	clc
	movzx ebx, multiplier
	mov eax, 0

	L1:
		mov dx, bx
		and dx, 0001
		cmp dx, 1
		clc
		jne skip1	
			add al, multiplicand
		Skip1:
		pushfd
		shr bx, 1
		mov edx, 0
		shrd dx, ax, 1
		shr dx, shcount
		or bx, dx
		shr ax, 1
		popfd
		jnc nocarry
			mov dx, 8000h
			shr dx, shcount
			OR ax, dx
		Nocarry:
	Loop L1	

	call writedec
	call crlf
	
	mov eax, ebx
	call writedec

	shld eax, edx, 100

	exit
main ENDP

end main