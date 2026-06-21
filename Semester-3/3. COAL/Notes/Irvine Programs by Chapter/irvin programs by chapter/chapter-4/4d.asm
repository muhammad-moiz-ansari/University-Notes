;OFFSET
; RETURN THE DISTANCE OF VARIABLE FROM THE BEGINNING OF ENCLOSED SEGMENT DS
.model small
.stack 0100h
.data
	val1 db 4
	val2 dw 5
	val3 dd 7
	val4 db 7
	ary db 1,2,3
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,val1
	mov si,offset val1
	mov si,offset val2
	mov si,offset val3
	mov si,offset val4
	mov si,offset ary
	mov si,offset ary+2
	
	
	
end start
					
mov ah,04ch
int 021h
end