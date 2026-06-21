;type return the size in bytes 
.model small
.stack 0100h
.data
	val1 db 4
	val2 dw 5
	val3 dd 7
	val4 dq 8
	val5 dt ?
  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,val1
	mov al,type val1		;1
	mov al,type val2		;2
	mov al,type val3		;4
	mov al,type val4		;8
	mov al,type val5		;10
	
end start
					
mov ah,04ch
int 021h
