; EQUAL(=)sign directive
;count define in code 

.model small
.stack 0100h
.data
	v1 db count			;count=7 as last declaration was 7
	v2 db count			;count=7
.code
 start:
	mov ax,@data
	mov ds,ax
	count = 5	
	mov ax,0
	mov al,v1				;al= v1  7
	mov bl,v2				;bl= v2  7
	count=7
	mov cl,count			;cl=7
	
end start	
mov ah,04ch	
int 21h

end