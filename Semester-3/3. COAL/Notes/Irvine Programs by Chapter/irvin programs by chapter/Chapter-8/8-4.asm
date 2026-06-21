;Chapter 8 Advance Procedures
;PRACTICE: Recursion 
;PROGRAM:  sum of counter values

.model small
.stack 0100h
.data
.code
JMP Main
sumcount proc	
	cmp cx,0
	je l2	
	add ax,cx
	dec cx
	call sumcount	
	l2: 	RET 
sumcount ENDP

main proc
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov cx,3
	call sumcount
			
main EndP	
	
mov ah,04ch
int 021h

end