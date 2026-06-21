.data
	data dw 8,-6,3,4
	swap db 1	
.code
start:
 mov ax,@data
 mov ds,ax
main Proc
	
mov ax,0
mov bx,0
mov swap,0
	
loop1:
	mov ax,data[bx]
	cmp ax,data[bx+2]
	jle noswap
		
	mov dx,data[bx+2]	
	mov data[bx+2],ax
	mov data[bx],dx
	mov swap,1		
noswap:
	add bx,1
	cmp bx,6
jne loop1	
cmp swap,1	
je main

mov ah,04ch
int 021h
