;align
.model small
.stack 0100h
.data
	v1 db 4
	v2 dw 1,2,3
	align 2			;align on even address
	v3 db 4
	align 4 			;work for .386
	v4 dw 5
	v5 dw 6
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,v1
	mov si,offset v1
	mov si,offset v2
	mov si,offset v3
	mov si,offset v4		
	
end start
mov ah,04ch
int 021h
end