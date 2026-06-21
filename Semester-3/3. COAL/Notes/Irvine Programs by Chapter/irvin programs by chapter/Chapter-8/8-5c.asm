;Fact program
;parameter passing through stack
;register saving

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    
.code
main PROC 
   mov eax,0
   mov al,1
   mov bx,3
   push bx
   mov ebx,012345678h
   call fact
   mov eax,0
INVOKE ExitProcess,0
main endp

fact proc
 push ebp
 push ebx
 mov ebp,esp
 mov bx,[ebp+12]
l1:
    cmp bl,1
    jb exit
    mul bl
    dec bl
    jmp l1
exit:
pop ebx
pop ebp
ret 2
fact endp
END main
