;FLAG --- overflow
  
.model small
.stack 0100h
.data
	v1 db 01Fh

.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,+127
	add al,+1				;overflow =1, where carryflag=0100h
	xor ax,ax
	sahf
	mov al,-128				
	sub al,1				;will set overflow flag
	xor ax,ax
	sahf	
	mov al,-128
	add al,-1				;will set overflow flag
	
end start
					
mov ah,04ch
int 021h
end