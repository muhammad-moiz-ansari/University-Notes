;Chapter 5 Procedures
; Practice PUSHA POPA

.model small
.stack 0100h
.286
.data

.code
	mov ax,1
	mov cx,2
	mov dx,3
	mov bx,4
	mov bp,5
	mov si,6
	mov di,7
	PUSHA 
	mov ax,15
	mov cx,14
	mov dx,13
	mov bx,12
	mov bp,11
	mov si,10
	mov di,9
	POPA
	
			
mov ah,04ch
int 021h

end
