.model small
.stack 0100h
.data
		v1 db 1
		exp equ 2*5
		txt equ <"ABC">
		txt2 equ <10*10>
		symb equ exp
		axmov equ <mov ax,v1>
		db 6		
		list db exp,txt,txt2,symb
		
.code
start:
 mov ax,@data
 mov ds,ax
 mov ax,0
 mov al,v1
 mov ax,txt2
 ;axmov

end start
	
mov ah,04ch	
int 21h

end