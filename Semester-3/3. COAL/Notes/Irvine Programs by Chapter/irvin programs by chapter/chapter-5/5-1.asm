;Chapter 5 Procedures
; Practice PUSH AND POP


.model small
.stack 0100h
.data
	Wval1 WORD 01234H
	Bval2 BYTE 9
	Wval3 WORD 0	
.code	
		mov ax,@data
		mov ds,ax
		mov ax,0
		mov ax,Wval1
		PUSH ax          ;Reg push
		PUSH Wval1		 ;Memory PUSH
		push 15      ;immediate push to stack .386 it push immediate as 32-bit number
		mov bx,0
		mov bl,bval2		;only word push
		PUSH bx
		POP bx
		POP Wval3
		POP ax		
			
mov ah,04ch
int 021h

end
