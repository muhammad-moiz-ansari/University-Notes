

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  mstart db 077h
	  fval1 real4 1.25
	  fval2 real8 2.50
	  fval3 real10 3.625
	  integer1 db 1
	  iword dw 2
	  idouble dd 3
	  iquard dq 4
	  mend	db 0FFh  
	
.code
main proc
	
	FINIT	
	mov eax, offset mstart
	FLD1
	FLDL2T			;log2 base 10
	FLDL2E			;log2 base E
	FLDPI			;load PI
	FLDLG2			;log10 to base 2
	FLDLN2			;loge to base 25
	FLDZ            ;load zero	
	;FLDZ            ;load zero	
	;FLDZ            ;load zero	
	invoke ExitProcess,0
main endp
end main