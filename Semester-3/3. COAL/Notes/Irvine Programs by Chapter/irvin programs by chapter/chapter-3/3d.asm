;First program

.model small

.stack 0100h

.data
	   val1 Byte  12h    ;	hexa
	   ;val2 Byte eh      ;error invalid initializer
	   val2 Byte 0eh      ;valid initializer number required before character
	   
.code
	start:
	mov ax,@data		   
	mov ds,ax			;;Data segment address move ax registers
	mov ax,0               ; zeroing ax registers
	
	mov al,val2-1
	
end start
					
mov ah,04ch
int 021h

end
