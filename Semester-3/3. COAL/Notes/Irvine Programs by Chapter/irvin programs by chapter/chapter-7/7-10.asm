;Unsigned Division
;8 bit unsigned division
;Dividend/divisor
 

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    Q db 110101b   	;8 bit Dividend
	A db 0		    ;Accumulator
	M db 111b		;divisor

.code
main PROC
	mov eax,0
	mov ah,A   		;accumulator 	
	mov al,Q		;Dividend
	mov bl,M
	mov cl,8	
	L1:
		SHL ax,1    ;Shift left A,Q
		sub ah,bl	; A=A-M
		jns qzero1	;if(A<0)
		and al,11111110b	;Q0=0
		add ah,bl			;A=A+M
		jmp skip			
		qzero1:
		OR al,1		 ;else if (A<0) Q0=1
		skip:	
	LOOP L1

   mov eax,0
INVOKE ExitProcess,0
main endp
END main