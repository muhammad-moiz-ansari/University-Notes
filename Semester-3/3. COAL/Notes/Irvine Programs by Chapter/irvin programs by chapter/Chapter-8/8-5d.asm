;Fact program
;parameter passing through stack
;recursive 

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    
.code
main PROC 
   mov eax,0
   mov ebx,0
   mov al,1
   push word ptr 3 
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
 cmp bl,1
 jb exit
 mul bl
 dec bl
 push bx
 call fact
exit:
pop ebx
pop ebp
ret 2
fact endp
END main
