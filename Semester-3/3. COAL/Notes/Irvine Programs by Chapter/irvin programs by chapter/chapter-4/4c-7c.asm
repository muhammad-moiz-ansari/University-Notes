;FLAG --- overflow
;Flag
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
	neg al				   ;overflow =1
	
	xor ax,ax
	sahf
	
	mov al,127
	neg al					; no overflow
	
end start
					
mov ah,04ch
int 021h
end