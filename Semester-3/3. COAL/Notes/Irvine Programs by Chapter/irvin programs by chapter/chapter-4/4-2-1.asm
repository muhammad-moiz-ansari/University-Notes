;INC & Flags affected

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
	v1 db 0FFH
.code
main PROC
  mov eax,0
  mov al,8 
  inc al     ;ZR=0, OF=0, AC= 0,PL(sign)=0, PE(parity)=1, CF= not affected,
  mov al,0FH
  inc al     ;ZR=0, OF=0, AC= 1,PL(sign)=0, PE(parity)=0, CF= not affected,
  inc al     ;ZR=0, OF=0, AC= 0,PL(sign)=0, PE(parity)=1, CF= not affected,
  mov al,+127		;or  7FH
  inc al     ;ZR=0, OF=1, AC= 1,PL(sign)=1, PE(parity)=0, CF= not affected,
  inc v1     ;increment memory  
		;ZR=1 , OF=1 , AC=1 ,PL(sign)=0, PE(parity)=1, CF= not affected,
	
  mov eax,0
INVOKE ExitProcess,0
main ENDP
END main
 