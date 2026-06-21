;First program
.model small
.stack 0100h
.data
	   v byte 0
	   ;val1 qword   3     			;	by default decimal ;0003 ;quard word
	   val2 qword   00123456789ABCDEFH  		  
	   val3 dword 2 dup(0CDEFH) 
	   val4 dq   00123456789ABCDEFH 
	   ;quad3 QWORD 'ABCDE'   ;error constant value too large
	  
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
