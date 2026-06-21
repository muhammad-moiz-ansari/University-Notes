;INDIRECT ADDRESSING
.model small
.stack 0100h
.data
	val1 db 1
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,val1
	
	;inc [si]				;will give error
	mov si,offset val1		; moving address
	mov bl,[si]				; mov to al what ever is at address si 
	inc byte Ptr[si]		; change byte val at address
	;inc [si]		; Error instruction operand must have size
	mov bl,[si]
	
	
end start
					
mov ah,04ch
int 021h
end