;PTR ; Let you over ride variable default size
.model small
.stack 0100h
.data
	v1 dd 089abcdefh
	v2 dd 012345678h
	r dd 0
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov ax, word ptr v1
	add ax, word ptr v2
	mov word ptr r,ax
	mov ax, word ptr v1+2
	adc ax, word ptr v2+2
	mov word ptr r+2,ax
	
end start
					
mov ah,04ch
int 021h
end