;First program
.model small
.stack 0100h
.data
	val1 db 4		;BYTE
	val2 dw 5
	val3 db 7	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0                ; zeroing ax registers
	mov cx,5				; constant to register
	mov dx,cx				; register to register mov
	;mov dx,cl				;ERROR size mismatch error
	mov al,val1				; mem to registers byte
	mov bx,val2				; mem to registers WORD
	;mov cx,val1			;ERROR invalid operands
	;mov val1,val3			;ERROR invalid operands
	mov cl,0FFH
	mov val1,cl				;register to MEM
	mov val2,15				;const to MEM(in deb translates to word ptr[val2],15)       
	 	
end start					
mov ah,04ch
int 021h
end