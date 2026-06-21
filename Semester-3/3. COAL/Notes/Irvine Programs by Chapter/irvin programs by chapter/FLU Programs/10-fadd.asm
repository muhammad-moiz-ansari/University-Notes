.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart dw 077h
	  fval1 real4 25.25
	  fval2 real4 95.675e-2
	  fval3 real4 0.0
	  mend	dw 0FFFFh  
	
.code
main proc
	
	FINIT	
	FLD fval1	
	FLD fval2
	FADD				;ADD ST(0)+ST(1) 
						;result temporary store in ST(1)
						;ST(0) is then popped
	invoke ExitProcess,0
main endp
end main