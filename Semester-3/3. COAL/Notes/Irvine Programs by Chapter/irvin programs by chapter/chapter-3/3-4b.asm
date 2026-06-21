; Practice DATE DECLARATION IN CODE
.model small
.stack 010h

.data	
	v1 db 1
	v2 db 2
			
.code
	start:
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov al,v1
.data 
	v3 db 3
	v4 db 4
.code
Proc start
	mov bl,v2
	mov cl,v3
Endp start
   			
mov ah,04ch
int 021h

end
