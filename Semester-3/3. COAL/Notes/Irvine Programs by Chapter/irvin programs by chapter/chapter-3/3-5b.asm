; EQUAL(=)sign directive
.model small
.stack 0100h
.data
	count=2*2+4-2		;count =6
	v1 db count			;count =6
	count=7
	v2 db count			;v2=7
	;fcount=2.5			;ERROR** BCD or real not Allowed
	;CountMax=4294967296		;value too large max take 32 bit integer
	CountMax=4294967294		    
.code
 
 start:
	mov ax,@data
	mov ds,ax
	count = 5	
	mov ax,0
	mov al,v1				;al= v1  6
	mov bl,v2				;bl= v2  7
	mov cl,count			;cl=5
	count=257;
	;mov cl,count		;** Error invalid instruction operands as 257 cannot fit
	mov cx,count		

end start	
mov ah,04ch	
int 21h
end