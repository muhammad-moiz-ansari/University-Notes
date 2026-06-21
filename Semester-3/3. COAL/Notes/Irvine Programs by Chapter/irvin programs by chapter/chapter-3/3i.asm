;First program

.model small
.stack 0100h
.data
	   list word  5 dup(0abcdh)       ;	by default decimal   
	   val2 word 255
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov ax,list	
	
end start
					
mov ah,04ch
int 021h

end
