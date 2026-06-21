;FLAG --- Zero Flag
.model small
.stack 0100h
.data
	val1 db -4
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,12
	sub al,12
	
	end start
					
mov ah,04ch
int 021h
end