.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart db 077h
	  fval1 real4 1.25
	  fval2 real4 3.5
	  fval3 real4 0.0
	  mend	dw 0FFFFh  
	
.code
main proc
	
	FINIT	
	mov eax, offset mstart
	FLD fval1			
	FLD fval2
	FST st(3)		;store st(0) to st(3)
	FST st(4)
	FST fval3		;store st(0) to fval3	

	invoke ExitProcess,0
main endp
end main