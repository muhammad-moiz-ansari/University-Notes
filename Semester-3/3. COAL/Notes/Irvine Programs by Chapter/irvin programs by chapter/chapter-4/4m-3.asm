;LOOP Instruction ****Nested LOOP***
.model small
.stack 0100h
.data
	temp dw 0
	
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov cx,2
outer:
	mov temp,cx
	mov cx,3
	inner:	
		inc ax
	  loop inner
    inc bx
	mov cx,temp
loop outer
	
end start
					
mov ah,04ch
int 021h
end