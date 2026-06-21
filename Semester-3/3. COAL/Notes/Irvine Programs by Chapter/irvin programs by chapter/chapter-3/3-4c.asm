
; Tbyte
.model small
.stack 010h

.data	
	v1 db 1
	val2 Tbyte 1234h
	val3 Tbyte 80000000000000001234h
	val3b Tbyte 89999999999999FF1234h  
	val4 Tbyte -1			; conver to hex & saved
	val5 Tbyte 16			;convert to hex & than saved
	
							;TO save them as BCD have to use FLD FDSTP
				
.code
start:
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov al,v1

End start
   			
mov ah,04ch
int 021h

end
