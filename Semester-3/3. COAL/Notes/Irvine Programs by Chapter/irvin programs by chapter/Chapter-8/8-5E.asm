;Fact program
;simple program

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    
.code
main PROC 
   mov eax,0
   mov eax,2
   call fact
   mov eax,0
INVOKE ExitProcess,0
main endp

fact proc
 cmp eax,0
 ja L1
 mov eax,1
 jmp L2
 L1:
 push eax
 dec eax
 
call fact
ReturnFact:
    pop eax
    mov ebx,eax
    mul ebx
L2: 
    ret 
fact endp
END main
