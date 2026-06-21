.386
.model flat, stdcall
.stack 4096
ExitProcess Proto, dwExitCode:dword

.DATA
	

.CODE
main Proc
	mov ah, 0
	mov al, 35h
	aaa

	mov ah, 0
	mov al, 05h
	aaa

	mov ah, 0
	mov al, 0A5h
	aaa

	mov ah, 0
	mov al, 3Ah
	aaa

	mov ah, 0
	mov al, 99h		;????????????????????????
	aaa

	mov ah, 0
	mov al, 88h
	aaa


	;Subtraction;

	clc
	mov ah, 0
	sub ah, 0
	mov al, 03h
	aas

	mov ah, 0
	mov al, 05h
	aas


	mov ah, 0
	mov al, 1h
	sub al, 1
	aas

	sub al, 9
	aas

	add ah, 3



	mov ah, 0
	mov al, 4h
	add al, -1
	aas

	sub al, 9
	aas

	add ah, 3




	mov ah, 0
	mov al, 3Ah
	aas

	mov ah, 0
	mov al, 99h		;????????????????????????
	aas

	mov ah, 0
	mov al, 88h
	aas


Invoke EXitProcess, 0
main Endp
End main