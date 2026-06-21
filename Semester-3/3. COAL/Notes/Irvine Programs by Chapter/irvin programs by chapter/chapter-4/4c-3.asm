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
	
	mov al,v1
	add al,1				;   CY=1  ZF =1 AC=1 PE=1
	
	xor ax,ax
    sahf	
	
	mov bl,1				; when subtract larger integer from smaller
							; Carry flag is set
	sub bl,2				;  CY=1 AC=1 PE=1  NG =1
	
		
end start
					
mov ah,04ch
int 021h
end