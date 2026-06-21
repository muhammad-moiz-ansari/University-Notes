.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart dw 077h
	  epsilon real4 1.0e-12
	  val2 real4 0.0
	  val3 real4 1.001E-13
	  N byte 0
	  mend	dw 0FFFFh  
	
.code
main proc
	;if(val2== val3)
	FINIT	
	FLD epsilon	
	FLD val2
	Fsub val3
	fabs
	fcomi st(0),st(1)
	ja skip
	;mWrite<"values are equal",0dh,0ah>
	skip:
	
	invoke ExitProcess,0
main endp
end main