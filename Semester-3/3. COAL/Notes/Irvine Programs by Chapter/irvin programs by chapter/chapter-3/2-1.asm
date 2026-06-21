; Student questions

.model small
.stack 010h

.data
	val1 db 1,2,3
	val1a db 4
	real1 dd 1.0		;  in memory	00 00 80 3F
	val2 db 1.0			; in memory 00
	val3 db 1+'a'		;  1+61 =62 in debugger
	;val4 db 255+3		;  Error  Initializer magnitude too large
	val5 db 0FFH
	
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov al,val1			; al=1
	mov bl,val1+1		; bl=2
	mov cl, val1a-1		; cl=3  ;val1 3rd element
	;mov cl,val1*2		;Error Constant expected
	;mov cl,val1+val1a	;Error Cannot add two relocatable labels
	
	mov cx,2023			;cx=07E7
	;mov ax,ax*3		; Invalid use of register
	;mov ax,3.5			;ERROR :Real or BCD number not allowed
	mov al,45o			;move octal                  		;al=25
	mov bl,45O			;move octal  with CAPITAL O			;al=25
	mov al,-45o			;move octal							;al=DB
	mov al,01010001B	;Binary in CAPITAL					;al=51
	mov al,-1001B		;-ve binary							;al=F7
	mov ax,'a'			;moving character to ax= 0061		;ax=0061
	mov ax,'ab'												;ax = 6162
	;mov ax, 5*val1		;constant expected
	;mov ax,AB12h		;ERROR undefined symbol AB12h		;no zero in the start
	mov ax,0AB12h		;NO ERROR  CORRECT 
	;mov al,755			;ERROR invalid instruction operands
	
	mov al,5*-3			; al=F1
	mov al,5*(-3)		; al=F1
	mov al,-(5*3)		; al=F1
	
	mov al,2(3)			; No Error 			al=05	wrong value
	mov al,5(-3)		; NO Error 			al=02  wrong value
	;mov al,(-3)5		;ERROR missing operator in expression
	
	
				
mov ah,04ch
int 021h

end
