;Sub & Flags affected
;DEC & Flags affected

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
	v1 db 0FFH
	v2 dw -1
.code
main PROC

  mov eax,0 
  mov al,6
  sub al,2  
  mov al,2
  sub al,6
;signed subtraction and flags
   mov al,-127
   sub al,+2

   mov al,-127
   sub al,-2

   mov al,+127
   sub al,+2

   mov al,+127
   sub al,-2


  mov eax,0
INVOKE ExitProcess,0
main ENDP
END main
 