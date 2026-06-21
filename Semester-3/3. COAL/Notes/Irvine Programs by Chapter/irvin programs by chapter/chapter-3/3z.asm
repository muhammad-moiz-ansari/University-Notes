;First program

.model small

.stack 0100h

.data
	   val1 dword   3.     ;	saving as fraction
	   val2 dword   3.23     ;	saving as fraction
	   val3 dword   -3.23     ;	saving as fraction
	   val4 dword   3.3E0     ;	saving as fraction
	   val5 dword   3.3E3     ;	saving as fraction
	   val6 dword   3.3E-3     ;	saving as fraction
	     
	   
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	;mov ax,val1
	
end start
					
mov ah,04ch
int 021h

end
