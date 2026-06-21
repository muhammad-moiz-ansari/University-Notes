;Finit
; setting floating point data type
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart db 077h
	  fval1 real4 1.25
	  fval2 real8 1.25
	  fval3 real10 1.25
	  mend	db 0FFh  
	
.code
main proc
	
	FINIT	
	mov eax, offset mstart

	invoke ExitProcess,0
main endp
end main