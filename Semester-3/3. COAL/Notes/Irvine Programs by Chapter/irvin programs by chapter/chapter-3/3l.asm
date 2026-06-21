;First program
.model small
.stack 0100h
.data
	   v byte 0
	   rval1 real4   -3.0     			;single precision floating point
	   rval2 real8 3.2e-260		   ;double precision floating
	   rval3 real10 4.6e+4096			; extended floating point rep
	  
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

