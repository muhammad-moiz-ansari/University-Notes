;OFFSET
; RETURN THE DISTANCE OF VARIABLE FROM THE BEGINNING OF ENCLOSED SEGMENT
.model small
.stack 0100h
.data
	ary dw 1,2,3
		dw 4,5,6,7
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov ax,ary
	mov ax,ary+6
	
	
end start
					
mov ah,04ch
int 021h
end