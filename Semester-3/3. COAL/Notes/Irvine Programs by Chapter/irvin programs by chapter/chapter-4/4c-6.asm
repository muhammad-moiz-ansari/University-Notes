;FLAG --- signed/negative  Flag
; important to understand difference in sign/unsigned add sub.. 
.model small
.stack 0100h
.data
	v1 db 01Fh

.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,-3			 	;-ve value to al
	mov bl,-5				;-ve value to al
	add al,bl				;Adding two negative number result is negative & will
							;set negative flag/signed flag
	xor ax,ax
    sahf							
		
	mov al,127			 	;+ve to al
	mov bl,127				;+ve value to al
	add al,bl				;Adding two negative number result is negative & will
							;set negative flag/signed flag
	xor ax,ax
    sahf							
		
	mov al,255		 	;-ve value to al
	mov bl,255			;-ve value to al
	add al,bl		
	
end start
					
mov ah,04ch
int 021h
end