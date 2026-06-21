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
	FADD fval2				;ADD ST(0) with memory & store in ST(0)
	invoke ExitProcess,0
main endp
end main