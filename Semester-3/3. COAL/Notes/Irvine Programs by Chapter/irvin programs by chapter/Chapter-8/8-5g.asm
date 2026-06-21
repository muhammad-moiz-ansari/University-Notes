;Fact program
;parameter passing through stack
;recursive book PROGRAM

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
   push 4 
   mov ebx,012345678h
   call fact
   mov eax,0
INVOKE ExitProcess,0
main endp

fact proc
 push ebp
 mov ebp,esp
 push ebx
 mov eax,[ebp+8]
 cmp eax,0
 ja L1
 mov eax,1
 jmp L2
 L1:
 dec eax
 push eax
 call fact
ReturnFact:
    mov ebx,[ebp+8]
    mul ebx
L2: 
    pop ebx
    pop ebp
    ret 4
fact endp
END main

