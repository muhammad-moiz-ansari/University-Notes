;Chapter 5 Procedures
; Practice PUSHA POPA  ax,cx,dx,bx,sp,bp,si,di
.model small
.stack 0102h
.286
.data
.code
	mov ax,1
	mov cx,2
	mov dx,3
	mov bx,4
	mov sp,5  ;incontrol of processor
	mov bp,6
	mov si,7
	mov di,8
	PUSHA 			;require .286
	mov ax,15
	mov cx,14
	mov dx,13
	mov bx,12
	mov bp,11
	mov si,10
	mov di,9
	POPA			;require .286
		
mov ah,04ch
int 021h

end
