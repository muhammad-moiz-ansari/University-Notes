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
	
	
	mov si,offset val1		; moving address
	;mov dx,[si]				;no error will read word from memory using indirect addressing
	mov al,[si]				; mov to al what ever is at address si 
	inc si
	add al,[si]
	inc si
	add al,[si]
	
	mov si,offset val2		; moving address
	mov bx,[si]				; mov to al what ever is at address si 
	inc si
	inc si
	add bx,[si]
	inc si
	inc si
	add bx,[si]
	
end start
					
mov ah,04ch
int 021h
end