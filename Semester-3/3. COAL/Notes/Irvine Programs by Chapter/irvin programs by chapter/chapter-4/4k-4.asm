;INDIRECT ADDRESSING
.model small
.stack 0100h
.data
	val1 db 1,2,3
	val2 dw 4,5,6
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,val1
	
	mov si,0	; moving address
	mov al,[val1+si]				; mov to al what ever is at address si 
	inc si
	add al,[val1+si]				; mov to al what ever is at address si 

	mov si,0	; moving address
	mov bx,[val2+si]				; mov to al what ever is at address si 
	add si,2
	add bx,[val2+si]				; mov to al what ever is at address si 

end start
					
mov ah,04ch
int 021h
end