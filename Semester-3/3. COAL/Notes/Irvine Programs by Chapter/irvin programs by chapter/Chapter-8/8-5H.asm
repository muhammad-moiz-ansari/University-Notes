;MUL instruction program

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    
.code
main PROC 
   mov eax,0
   mov ebx,0
   mov al,255
   mov bl,2
   mul bl               ;AX = AL * BL
   mov ax,-1
   mul bx               ;DX:AX= AX * BX

   mov eax,-1
   mov ebx,-1
   mul ebx       		;EDX:EAX = EAX * EBX


   mov eax,0
INVOKE ExitProcess,0
main endp
END main
