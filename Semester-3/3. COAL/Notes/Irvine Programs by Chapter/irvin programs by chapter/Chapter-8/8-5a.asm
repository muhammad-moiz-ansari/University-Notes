;Factorial program
;Fact function Parameter to BX register
;Return factorial in AX register

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    
.code
main PROC 
   mov eax,0
   mov al,1
   mov bl,3
   call fact
   mov eax,0
INVOKE ExitProcess,0
main endp

fact proc
 
l1:
    cmp bl,1
    jb exit
    mul bl
    dec bl
    jmp l1
exit:
ret 
fact endp
END main
