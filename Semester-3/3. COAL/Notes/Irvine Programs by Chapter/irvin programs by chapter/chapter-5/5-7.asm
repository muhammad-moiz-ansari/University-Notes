;Chapter 5 Procedures
; Practice ADD Array saving registers in stack

.model small
.stack 0100h
.data
	ary db 1,2,3,4,5
.code

JMP START
    sumary proc
	
	push si
	push cx
	mov ax,0
	l1:
		add al,Byte PTR[si]
		inc si
		LOOP l1
	pop cx
	pop si
	
	ret		
sumary ENDP
	
START:
		
	mov ax,@data
	mov ds,ax	
	
	main proc
	
	 mov si,OFFSET ary
	 mov cx,lengthof ary
	 call sumary
	
	main EndP	
	
mov ah,04ch
int 021h

end