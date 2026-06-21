.386
.model flat, stdcall
.stack 4026
ExitProcess Proto, dwExitcode: DWord

.DATA
	string db "Encircle your course instructor name to score the bonus", 0
	sizel = $-string - 1
	s1 = sizel/2 + 1
	stringcopy dw s1 dup ("?")

.CODE
main PROC
	mov esi, 0		;offset string
	mov edi, 0
	mov ecx, sizel/2 + 1

	L1:
		mov al, string[esi]
		inc esi
		mov ah, string[esi]
		inc esi

		mov stringcopy[edi], ax
		add edi, 2

	Loop L1

Invoke ExitProcess, 0

main ENDP
END main