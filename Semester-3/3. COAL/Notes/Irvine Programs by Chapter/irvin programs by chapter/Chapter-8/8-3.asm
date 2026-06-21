;Chapter 8 Advance Procedures
; Practice LOCAL VARIABLES
;parameter passing through registers 
;clear stack in RET
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    
.code
main PROC 
   mov eax,0
   mov ax,1
   mov bx,10
   call swap
   mov eax,0
INVOKE ExitProcess,0
main endp

swap proc
	push ebp
	mov ebp,esp
	sub esp,2
	mov WORD PTR [ebp-2],bx
	mov bx,ax
	mov ax,WORD PTR[ebp-2]
	mov esp,ebp
	pop ebp
	RET 
swap Endp
END main
