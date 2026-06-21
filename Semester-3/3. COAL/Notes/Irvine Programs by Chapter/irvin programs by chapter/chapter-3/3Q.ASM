;First program
.model small
.stack 0100h
.data
	   
	   list byte 1,2,3,4,5
	   sizelist = $-list
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,list
	mov bl,sizelist
	
end start
					
mov ah,04ch
int 021h
end