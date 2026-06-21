;Fact program
;parameter passing through stack

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
   call fact
   mov eax,0
INVOKE ExitProcess,0
main endp

fact proc
 push ebp
 mov ebp,esp
 mov bx,[ebp+8]
l1:
    cmp bl,1
    jb exit
    mul bl
    dec bl
    jmp l1
exit:
pop ebp
ret 
fact endp
END main
