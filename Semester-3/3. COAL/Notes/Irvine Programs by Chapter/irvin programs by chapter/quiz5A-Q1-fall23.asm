.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
.data
    array byte 7,8,9
	res word ?        
.code
main Proc
	mov esi, OFFSET array
	push esi
	mov esi,sizeof array
	push esi
	mov eax,0
	call sampleproc
	mov res,ax
	mov bx,0
INVOKE ExitProcess,0
main ENDP

sampleproc proc
	Push ebp
	mov ebp,esp
	mov esi,[ebp+12]
	mov ecx,[ebp+8]
	cmp ecx,0
	je L1
	add al,[esi]
	dec ecx
	inc esi
	push esi
	push ecx	
	call sampleproc
	L1:
		pop ebp
	ret 8	
sampleproc endp
END main
