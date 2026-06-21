 ;First try

.model small
.stack 0100h
.data
	valb_1 BYTE 'A'
	valb_2 BYTE  0
	valb_3 DB  256
	valb_4 BYTE -128
	;valb_4a BYTE -129		;MASM does not give Error 
							; Emulator does
	valb_5 BYTE +127
	valb1_6 SBYTE -128
	valb1_7 SBYTE +127
	valb1_8 SBYTE -2h

.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	
	mov bl, valb_1
	mov cl, valb_2
	;mov al,2*200   ;ERROR: invalid instruction operand - 			
mov ah,04ch
int 021h

end
