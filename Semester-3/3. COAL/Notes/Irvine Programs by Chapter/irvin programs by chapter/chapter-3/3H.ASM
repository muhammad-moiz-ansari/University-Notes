;First program

.model small
.stack 0100h
.data
	   ;val byte 1
	   ;val1 word 1
	   ;val2 word 0abcdh
	   ;val3 word 01234h
	   ;list word   1,2,3,4     ; 2 bytes 16 bit
  	   val4 dw 0EEFFH				;define word
.code
start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov ax,val4
	;mov bx,val1
	;mov cx,val2
	;mov dx,val3
	
	;mov ax,list
	;mov bx,list+2			; 0+2bytes	
	;mov cx,list+4			;0+4 = will access 3rd word
	;mov dx,list+6			;0+4 = will access 3rd word

end start
					
mov ah,04ch
int 021h

end
