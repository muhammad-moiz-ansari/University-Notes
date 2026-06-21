.386
.model flat, stdcall
.stack 4096
ExitProcess Proto, DWExitCode:DWord

.DATA
	num dd 1234ABCDh
	arr db 32 dup('0')
	temp dw ?

.CODE
main Proc
	mov ebx, num
	mov ecx, 8 * 4
	mov esi, offset temp - 1
	mov dl, '1'

	L1:
		mov al, bl
		and al, 1
		cmp al, 1
		je J1
		jmp else1
		J1:
			mov [esi], dl
		else1:
		
		dec esi
		shr ebx, 1
	Loop L1

Invoke ExitProcess, 0
Main Endp
End Main