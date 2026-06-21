;FLAG --- Auxiliary Flag
.model small
.stack 0100h
.data
	v1 db 00Fh
.code
	start:
	mov ax,@data		  
	mov ds,ax
	mov ax,0        ; zeroing ax registers
	
	mov al,00Fh
	add al,1		;AC=1
					;will set the Auxiliary Flag	
end start					
mov ah,04ch
int 021h
end