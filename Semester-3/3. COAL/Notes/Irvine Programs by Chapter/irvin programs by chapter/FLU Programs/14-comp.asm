.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart dw 077h
	  x real4 1.2
	  y real4 3.0
	  N byte 0
	  mend	dw 0FFFFh  
	
.code
main proc
	;if(x<y)
	;	N=1;
	FINIT	
	FLD x	
	Fcomp y
	FNSTSW ax		;mov status word to ax
	sahf			;copy ah to status flag
	jnb L1
	mov N,1
	L1:
	
	invoke ExitProcess,0
main endp
end main