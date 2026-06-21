;FLAG --- Parity Flag
; when least significant byte of destination register has an even nymebr of one
.model small
.stack 0100h
.data
	v1 db 01Fh
.code
	start:
	mov ax,@data		   
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,v1
	add al,00100000b	; PE = 1
						; will set the parity Flag as number of 1 
						;will become even
	XOR ax,ax
	Sahf
	
	mov ax,002Fh
	inc ax				;PE=1, AC=1
	
	XOR ax,ax
	Sahf
	
	mov ax,0F0FH
	sub ax,03H			;PE=1
	
end start					
mov ah,04ch
int 021h
end