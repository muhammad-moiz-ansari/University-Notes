;LOOP Instruction ****Nested LOOP***
.model small
.stack 0100h
.data
	temp db 0
	
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,4
outer:
	mov temp,cl
	mov cl,3
	inner:	
		inc ax
		loop inner
    inc bx
	mov cl,temp
loop outer
	mov dx,1   ;end of nested loop
	
end start
					
mov ah,04ch
int 021h
end