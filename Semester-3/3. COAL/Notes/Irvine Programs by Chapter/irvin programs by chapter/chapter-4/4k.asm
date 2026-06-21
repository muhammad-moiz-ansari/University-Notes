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
	
	mov si,offset val1		; moving address  ; tried mov ax,offset val1  ; works fine
	mov al,[si]				; mov to al what ever is at address si 
	inc si
	add al,[si]
	inc si
	add al,[si]
	inc si
	add al,[si]
	
end start
					
mov ah,04ch
int 021h
end