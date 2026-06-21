;PTR ; Let you over ride variable default size
.model small
.stack 0100h
.data
	val1 db 4
	val2 dw 5
	val3 db 7
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,val1
	;mov cl,val2				;ERROR invalid operands
	;mov dx,val3
	mov dx, WORD PTR val1
	mov cl, BYTE PTR val2
	
end start
					
mov ah,04ch
int 021h
end