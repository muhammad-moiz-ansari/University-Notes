; Practice DATE DECLARATION
; TWORD
;PACKED BCD

.model small
.stack 010h

.data	
	v db 0FFH
	rval1 REAL4 -1.2
	rval2 REAL8 3.2E-260
	rval3 REAL10 4.6E+4096
	
	r1 DD -1.2
	r2 DQ 3.2E-260
	r3 DT 4.6E+4096	
		
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov al,v	
	
				
mov ah,04ch
int 021h

end
