;FLAG --- zero Flag
.model small
.stack 0100h
.data
	val1 db -4
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax register
	
	mov bx, 0FFFFH
	add bx,1
	
	;LAHF
	;AND AH,06				;position of zero flag
		
end start
					
mov ah,04ch
int 021h
end4c