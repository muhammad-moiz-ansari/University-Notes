.386
.model flat, stdcall
.stack 4026
ExitProcess Proto, dwExitcode: DWord

.DATA
	var1 byte 35

.CODE
main PROC
	push 3
	push ax
	push eax

Invoke ExitProcess, 0

main ENDP
END main