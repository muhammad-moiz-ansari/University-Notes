;variable +2 using pass by reference
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    v1 dw 5
    v2 dw 6    
.code
main PROC 
   mov eax,0
   push offset v1
   push offset v2
   call sum
   mov eax,0
INVOKE ExitProcess,0
main ENDP
sum proc
    push ebp
    mov ebp,esp
    mov esi,[ebp+12]
    add word ptr [esi],2
    mov esi,[ebp+8]
    add word ptr [esi],2
    pop ebp
    ret 8
sum endp
END main