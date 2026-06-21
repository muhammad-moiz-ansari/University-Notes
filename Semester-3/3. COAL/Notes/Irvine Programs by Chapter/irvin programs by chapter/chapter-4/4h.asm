;length return number of elements in an array
.model small
.stack 0100h
.data
	val1 byte 10,20,30
		byte 11,12,13
		
	val2 db 1,2,3,
			4,5,6
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,val1
	mov al,lengthof val1       ;3
	mov al,lengthof val2	   ;6
		
	
end start
					
mov ah,04ch
int 021h
end