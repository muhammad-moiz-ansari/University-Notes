.model small
.stack 0100h
.data
	ary db 1,2,3
.code

JMP START
    
sum_ary proc
	push bp
	mov bp,sp
	push cx
	push si
	mov si,[bp+6]
	mov cx,[bp+4]	
	mov ax,0
	
	l1:
		add al,Byte PTR[si]
		inc si
		LOOP l1
	pop si
	pop cx
	pop bp
	ret 4
sum_ary ENDP
	
START:
main proc
	mov ax,@data
	mov ds,ax		 
	
	 mov si,OFFSET ary
	 PUSH si	 
	 mov si,lengthof ary
	 push si
	 mov cx,0FFFFh
	 mov si,0FFFFh
	 call sum_ary
	; add sp,4					;C convention
	main EndP	
	
mov ah,04ch
int 021h
end