.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart dw 077h
	  fval1 real4 -1.25
	  fval2 real4 0.0
	  fval3 real4 0.0
	  mend	dw 0FFFFh  
	
.code
main proc
	
	FINIT	
	FLD fval1
	FABS				;absolute
	FST fval2		
	FABS
	FCHS				;sign change
	FST fval3
	invoke ExitProcess,0
main endp
end main