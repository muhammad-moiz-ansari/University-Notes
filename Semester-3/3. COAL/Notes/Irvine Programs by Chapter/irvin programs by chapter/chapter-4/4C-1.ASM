;  Neg instruction
.model small
.stack 0100h
.data
	val1 db 4
	val2 dw 5
	val3 db -7	  
.code
start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers	
	mov al,val1
	neg al	
	neg val3	
end start					
mov ah,04ch
int 021h
end