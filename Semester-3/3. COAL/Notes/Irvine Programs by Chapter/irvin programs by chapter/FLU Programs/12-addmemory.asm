.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart dw 077h
	  fval1 real4 25.25
	  fval2 real4 95.675e-2
	  mend	dw 0FFFFh  
	
.code
main proc
	
	FINIT	
	FLD fval1	
	FLD fval2				
	;FADD st(0),st(2)	 ;RUN TIME EXCEPTION
	FADD ST(0),ST(1)			;ADD ST(0) with ST(1)
	FADD ST(1),ST(0)			;ADD ST(0) with ST(1)
	invoke ExitProcess,0
main endp
end main