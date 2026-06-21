;First program

.model small

.stack 0100h

.data
	        Byte  5    ; no label so optional label    
	   val2 Db 6    ;save as byte
	   
.code

start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	;mov bl, val1
	mov al,	val2-1			;will access byte before val2
end start					
mov ah,04ch
int 021h

end
