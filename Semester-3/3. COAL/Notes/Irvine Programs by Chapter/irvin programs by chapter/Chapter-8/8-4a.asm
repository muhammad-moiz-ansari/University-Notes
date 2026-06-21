;Chapter 8 Advance Procedures
;PRACTICE: Recursion 
;PROGRAM:  sum of counter values

.model small
.stack 0100h
.data
.code
JMP Main
sumcount proc
	PUSH BP			
	mov bp,sp		
	push cx	
	mov cx,[bp+4]
	cmp cx,0
	je l2	
	add ax,cx
	dec cx
	Push cx
	call sumcount	
	l2:
	pop cx
	mov sp,bp				;Removing space from stack created for local variable
	POP bp
	RET 2	
sumcount ENDP
main proc
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov bx,2
	push bx
	call sumcount			
main EndP		

mov ah,04ch
int 021h
end