;First program
.model small
.stack 0100h
.data
	   v byte 0
	   rval1 dd   -3.0     			;	single precision floating point
	   rval2 dq	3.2e-260		   ;double precision floating
	   rval3 dt 4.6e+4096			; define 10 byte
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,v
end start
					
mov ah,04ch
int 021h
end
D