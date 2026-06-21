;FLAG --- Zero Flag
.model small
.stack 0100h
.data
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0          ; zeroing ax registers
	
	mov cl, 0FFH
	inc cl				;cl=0  ZF=1, PE=1, AX=1
	
	xor ax,ax
    sahf	
	
	inc cl			
	dec cl				;cl=0    ZF=1 , PE=1
	
end start
					
mov ah,04ch
int 021h
