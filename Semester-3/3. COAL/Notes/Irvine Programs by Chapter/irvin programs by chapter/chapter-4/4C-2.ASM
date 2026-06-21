;FLAG --- Zero Flag
.model small
.stack 0100h
.data
	val1 db -4
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0           ; zeroing ax register	
	mov al,val1
	add al,4			; ZF =1 AC=1 PE=1 CY=1
	
	xor ax,ax
    sahf			    ; required to reset flag register
	
	mov bx, 0FFFFH
	add bx,1			; ZF =1 AC=1 PE=1 CY=1
	
	xor ax,ax
    sahf				; required to reset flag register
	
	mov al,4
	sub al,4			;  ZF =1  PE=1 
	
	xor ax,ax
    sahf			; required to reset flag register
	
	mov ax,1
	dec ax			; ZF =1 PE=1 
	
	xor ax,ax
    sahf			; required to reset flag register
	
	mov cl,0
	neg cl			; ZF =1 PE=1 
		
end start
					
mov ah,04ch
int 021h
end