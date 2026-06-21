	;Chapter 5 Procedures
; Practice ADD SUM PROG

.model small
.stack 0100h
.data
	

.code

JMP START

sum proc
			add ax,bx
			add ax,cx
		RET
	sum ENDP
	
START:
		
	mov ax,@data
	mov ds,ax	
	
	main proc
		mov ax,1
		mov bx,2
		mov cx,3
		call sum
	
	main EndP	
	
mov ah,04ch
int 021h

end