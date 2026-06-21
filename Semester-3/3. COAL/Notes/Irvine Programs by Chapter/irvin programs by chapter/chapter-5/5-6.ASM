;Chapter 5 Procedures
; Practice ADD SUM PROG

.model small
.stack 010h
.data
	ary db 1,2,3,4,5
.code

JMP START
    sumary proc
	mov ax,0
	l1:
		add al,Byte PTR[si]
		inc si
		LOOP l1
	
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
