;add sum 
;parameter passing through stack
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
    mov esi,[ebp+8]
    mov ecx,[ebp+12]
    mov eax,0
    l1:
        add al,byte ptr[esi] 
        inc esi
    loop l1
    pop ebp
sum endp
END main
