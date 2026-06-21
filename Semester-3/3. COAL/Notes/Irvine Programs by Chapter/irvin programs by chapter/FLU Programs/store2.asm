.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart dw 077h
	  fval1 real4 1.25
	  fval2 real8 3.5
	  fval3 real4 0.0
	  mend	dw 0FFFFh  
	
.code
main proc
	
	FINIT	
	mov eax, offset mstart
	FLD fval1			
	FLD fval2		;fval2 is of size quard
	FST fval3		;store st(0) to fval3	
	FILD mstart
	FIST mend
	invoke ExitProcess,0
main endp
end main