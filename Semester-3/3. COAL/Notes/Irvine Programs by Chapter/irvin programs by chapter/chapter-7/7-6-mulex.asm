; Practice 16 bit x 16 bit multiplication algorithm 
;Shift Left ,rcl, adc
			
.model small
.stack 010h
.data	
	multiplicand dd 05A5AH      ;16 bit mutiplicand	
	multiplier dw 05Ah			;16 bit multiplier
	result dd 0					;32 bit answer	
.code 
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov ax, Word Ptr[multiplicand]   ;Mov lower word of multiplicand to ax
	mov bx, Word Ptr[multiplicand+2] ;Mov higher word of multiplicand to bx	
	mov dx,multiplier 				 ;multiplier to dx
	mov cx,16						 ;16 bit to 16 bit multiplication
	
	l1:
		Shr dx,1					;shift right multiplier by 1 bit
		jnc noadd
		
		add word PTR[result],ax		;add lower word to result
		adc word PTR[result+2],bx	;add through carry higher word to result	
	noadd:
		Shl ax,1
		RCL bx,1
	Loop l1
	
mov ah,04ch
int 021h

end
