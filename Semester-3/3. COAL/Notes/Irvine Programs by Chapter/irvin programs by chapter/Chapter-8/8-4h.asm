;ary sum program recursion
;parameter passing through stack
;register saving on stack
;clearing stack
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary1 db 1,2,3,4    
.code
main PROC 
   mov eax,0
   push dword ptr sizeof ary1
   push dword ptr offset ary1
   call sum
   mov eax,0
INVOKE ExitProcess,0
main endp

sum proc
    push ebp
    mov ebp, esp
    push esi
    push ecx
    mov esi,[ebp+8]
    mov ecx,[ebp+12]
    cmp ecx,0
    je exit
    
	add al,[esi]
	inc esi
	dec ecx
	
	push esi
	push ecx
	call sum
	exit:
    pop ecx
    pop esi
    pop ebp
    ret 8
sum endp
END main
;DEC & Flags affected
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary1 db 1,2,3,4    
.code
main PROC 
   mov eax,0
   push dword ptr sizeof ary1
   push dword ptr offset ary1
   call sum
   mov eax,0
INVOKE ExitProcess,0
main endp

sum proc
    push ebp
    mov ebp, esp
    push esi
    push ecx
    mov esi,[ebp+8]
    mov ecx,[ebp+12]
    cmp ecx,0
    je exit
    
	add al,[esi]
	inc esi
	dec ecx
	exit:
    pop ecx
    pop esi
    pop ebp
    ret
sum endp
END main
