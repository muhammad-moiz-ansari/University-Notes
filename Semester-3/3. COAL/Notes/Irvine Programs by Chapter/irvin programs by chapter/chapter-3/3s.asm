;First program
.model small
.stack 0100h
.data
	   
	   list  byte 'a long string of character is always difficult to count'
	   sizelist = $-list
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,list
	mov bl,size
	
end start
					
mov ah,04ch
int 021h
end