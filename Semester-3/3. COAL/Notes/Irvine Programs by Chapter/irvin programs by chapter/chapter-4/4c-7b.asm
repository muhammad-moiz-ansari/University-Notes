;FLAG --- overflow
  Flag
.model small
.stack 0100h
.data
	v1 db 01Fh

.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,-128
	sub al,1				;overflow =1
	
end start
					
mov ah,04ch
int 021h
end