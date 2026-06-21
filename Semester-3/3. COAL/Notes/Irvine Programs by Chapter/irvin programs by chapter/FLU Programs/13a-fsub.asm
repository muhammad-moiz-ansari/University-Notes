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
	FSUB				;sub ST(0)from ST(1) 
						;result temporary store in ST(1)
						;ST(0) is then popped
	Fsub fval2 		;ST(0)-= fval2
	FLD fval1
	Fsub st(2),ST(0)		;subtracting st(0) from ST(2) storing in St(2)
	invoke ExitProcess,0
main endp
end main