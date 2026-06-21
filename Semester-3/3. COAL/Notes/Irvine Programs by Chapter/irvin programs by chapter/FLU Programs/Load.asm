

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart db 077h
	  fval1 real4 1.25
	  fval2 real8 2.50
	  fval3 real10 3.625
	  mend	db 0FFh  
	
.code
main proc
	
	FINIT	
	mov eax, offset mstart
	FLD fval1
	FLD fval2
	FLD fval3
	FLD st(2)

	invoke ExitProcess,0
main endp
end main