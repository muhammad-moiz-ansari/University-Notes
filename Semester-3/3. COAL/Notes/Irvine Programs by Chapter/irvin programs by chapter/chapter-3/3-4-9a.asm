;floating point

.model small
.stack 0100h
.data
	   v1 db 2
	   v2 dd 2.25
	   v3 db 3	   
.code
start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,v1
		
end start
					
mov ah,04ch
int 021h

end
