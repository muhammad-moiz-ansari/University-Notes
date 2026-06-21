.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart dw 077h
	  fval1 dword 1
	  fval2 word 2
	  mend	dw 0FFFFh  
	
.code
main proc
	
	FINIT	
	FILD fval1	
	FIADD fval2
	invoke ExitProcess,0
main endp
end main