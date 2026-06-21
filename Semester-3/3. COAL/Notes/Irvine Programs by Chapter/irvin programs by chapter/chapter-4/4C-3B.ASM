;FLAG --- carry Flag
.model small
.stack 0100h
.data
	v1 db 0FFh

.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov bl,1
	sub bl,2				;  set carry flag
	
	xor ax,ax
    sahf	
	
	mov cl,v1
	inc cl
end start
					
mov ah,04ch
int 021h
