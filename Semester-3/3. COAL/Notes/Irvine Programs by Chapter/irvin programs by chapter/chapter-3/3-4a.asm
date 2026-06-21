
; Practice DATE DECLARATION
; TWORD
;PACKED BCD

.model small
.stack 010h
.data	
	v db 0
	tval1 TBYTE 01234H   ;	
	;tval2 TBYTE -1234   ;ERROR as it takes hex value book 3.4.8
						  ; no error in masm
	tval3 TBYTE +1    ;
	tval4 TBYTE -1    ;
			
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov bl,v
	mov ax,OFFSET tval1
	
				
mov ah,04ch
int 021h

end
