
;inc/dec
.model small
.stack 0100h
.data
	val1 db 4
	val2 dw 5
	val3 db 7
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	inc cl
	inc cl	
	dec cx
	
	inc val1				;convert to inc byte ptr[val1] on debugger
	dec val1
	dec val2
	;dec 5   ; ERROR
	
	
end start
					
mov ah,04ch
int 021h
end