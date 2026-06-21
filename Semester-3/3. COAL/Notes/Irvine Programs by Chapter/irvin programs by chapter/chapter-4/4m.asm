;LOOP Instruction
.model small
.stack 0100h
.data
	
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cx,3
Label1:		

	inc ax
	add bx,2
	loop Label1			 ;Decrement and cmp
    inc dx	
	
end start
					
mov ah,04ch
int 021h
end