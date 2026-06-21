;First program
.model small
.stack 0100h
.data
	   
	   list word 1,2,3,4,5
	   sizelist = $-list/2
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov ax,list
	mov bl,size
	
end start
					
mov ah,04ch
int 021h
end