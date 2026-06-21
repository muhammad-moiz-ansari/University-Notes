; EQUAL(=)sign directive

.model small
.stack 0100h
.data
	v1 db count			;count=5
	v2 db count			;count=5
.code
 start:
	mov ax,@data
	mov ds,ax
	count = 5	
	mov ax,0
	mov al,v1				;al= v1  5
	mov bl,v2				;bl= v2  5
	mov cl,count			;cl=5
	
	
end start	
mov ah,04ch	
int 21h

end