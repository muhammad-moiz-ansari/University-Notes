;First program

.model small

.stack 0100h

.data
	   val1 Byte  14     ;	by default decimal
	   val2 Byte  14d     ;	decimal
	   val3 Byte  16o     ;	octal
	   val4 Byte  16q     ;	octal
	   val5 Byte  1110b     ;	binary
	   val6 Byte  00001110b     ;	binary
	   val7 Byte  'a'           ;	character
	   val8 Byte 0eh      		;hexdecimal
	   val9 Byte  14h				
	   
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,val1
	
end start
					
mov ah,04ch
int 021h

end
