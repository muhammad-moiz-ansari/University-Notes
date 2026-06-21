;First program

.model small

.stack 0100h

.data
	   val1 Byte  ?    ; value not intialize will intialize it run time randomvalue
	   val2 Db 0110b    ;
	   
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,0FFh
	mov val1,al
	
	
end start
					
mov ah,04ch
int 021h

end
