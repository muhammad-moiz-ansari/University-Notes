;First program

.model small

.stack 0100h

.data
	   val1 Byte   3    	   ;by default decimal
	   val2 Byte  -3     	   ;saved in 2's complement
	   val3 sByte  130    	   ;save as 130
	   val4 sByte  -130         ;saved wrongly truncated sign bit 
								;*****kindly see code***  why -130 is not saved properly
	   val5 sByte  255     ;by default decimal
	     
	   
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	mov al,val4				;it will mov 07Eh code for 126d
	add al,30				;add 126+30= 156d  =09cH
	
end start
					
mov ah,04ch
int 021h

end
