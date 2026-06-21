;Chapter 8 Advance Procedures
;PRACTICE: Recursion 
;PROGRAM:  FACTORIAL

.model small
.stack 0100h
.data
.code

JMP Main

fact proc	
	cmp cx,0
	je l2	
	mov bx,cx
	mul bx
	dec cx
	call fact	
	l2:		
	RET 
fact ENDP

main proc
	mov ax,@data
	mov ds,ax
	mov ax,1
	mov cx,3
	call fact			
main EndP	
	
mov ah,04ch
int 021h
END