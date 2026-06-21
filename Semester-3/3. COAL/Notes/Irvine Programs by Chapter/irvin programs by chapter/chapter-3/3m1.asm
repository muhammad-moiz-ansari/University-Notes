;PACKED BCD NUMBERs
.model small
.stack 0100h
.data
	   v byte 0
	   tval1 tbyte 01234h
	   tval2 tbyte 80102030405060708090h 
	   tval3 tbyte 801A2B3c405060708090h 
	   tval4 tbyte -12
	   v2 byte 'AAAA'			; saved as string
	   
		
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,v
end start
					
mov ah,04ch
int 021h
end
