;First program
.model small
.stack 0100h
.data
	   v byte 0
	   val1 dword   3     			;	by double word 32-bit ---4 bytes	
	   val2 dword   089ABCDEFH  		  
	   val3 dword  2 dup(0CDEFH) 	 
	   val4 dd  3     			        ;define double word
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
