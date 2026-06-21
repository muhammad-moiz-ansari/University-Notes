;INDIRECT ADDRESSING
.model small
.stack 0100h
.data
	val1 db 1,2,3
	val2 dw 4,5,6
	;val3 dd 4,5,6
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,val1
	
	mov si,0	; moving address
	mov al,val1[si]				; 
	inc si
	add al,val1[si]				;

	mov si,0	; moving address
	mov bx,val2[si]				
	mov si,1*type val2
	add bx,val2[si]	
	mov si,2*type val2
	add bx,val2[si]
	
	;mov esi,0	; moving address
	;mov ebx,[val3+esi]				
	;inc esi
	;add ebx,[val3+esi*4]	
	
end start
					
mov ah,04ch
int 021h
end