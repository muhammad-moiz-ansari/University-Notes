;ADD & Flags affected

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
  mov al,+127
  add al,1
  add v2,1     ;OV = 0  PL = 0 ZR = 1 AC = 1 PE = 1 CY = 1  
  mov al,0FH
  add al,1     ;ZR=0, OF=0, AC= 1,PL(sign)=0, PE(parity)=0, CY= 0
  add al,1     ;ZR=0, OF=0, AC= 0,PL(sign)=0, PE(parity)=1, CY= 0
  mov ax,0F000H   
  add ax,1000H   ;OV = 0 PL = 0 ZR = 1 AC = 0 PE = 1 CY = 1 
  
  mov eax,0
INVOKE ExitProcess,0
main ENDP
END main
 