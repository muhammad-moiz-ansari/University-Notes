.model small
.stack 0100h
.data
		v1 db 1
		exp equ 2*5				;expression solve to int
		;exp equ 9   ;***Error Symbol exp cannot be redefine using EQU symbol
		;exp= 20	; Error redefine
							 
		txt equ <"ABC">			;text
		txt equ <"abc">			;text	***;for text no error of redefine
				txt2 equ <10*10>		;text
		symb equ exp
		mv equ mov
		axmov equ <mv al,v1>	;  work as statement for EQU
		axmove equ <mov al,v1>	;  work as statement for EQU
		db 6		
		list db exp,txt,txt2,symb
		axmov equ <mv bl,v1>
.code
start:
 mov ax,@data
 mov ds,ax
 mov ax,0
 mov al,v1
 mov ax,txt2 	; mov ax,64  10*10= 100 = 64h 
 axmov			;  work for EQU
 axmove			;  work for EQU
 axmov equ <mv cl,v1>		;** will update the valur of mov statement
 axmov

end start
	
mov ah,04ch	
int 21h

end