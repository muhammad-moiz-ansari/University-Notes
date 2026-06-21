

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart db 077h
	  fval1 real4 1.25
	  fval2 real8 2.50
	  fval3 real10 3.625
	  integer1 db 1
	  iword dw 2
	  idouble dd 3
	  iquard dq 4
	  mend	db 0FFh  
	
.code
main proc
	
	FINIT	
	mov eax, offset mstart
	;FLD integer1			;invalid operand
	;FILD integer1			;invalid size...
	FILD iword
	FILD idouble	
	FILD iquard
	invoke ExitProcess,0
main endp
end main