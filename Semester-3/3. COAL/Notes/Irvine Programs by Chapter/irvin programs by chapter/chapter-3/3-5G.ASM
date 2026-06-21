;<text macro>
.model small
.stack 0100h
.data
		v1 db 1
		exp textequ %(2*5)
		exp textequ %(20)		;redefining Exp
		txt textequ <"Message">
		txt2 textequ txt		; equaling already define symbol
		move textequ <MOV>
		axmov textequ < move al,v1>
		msg db txt,txt2
		db 6		
		;list db exp,txt,move, msg
.code
start:
 mov ax,@data
 mov ds,ax
 mov ax,0
 mov al,v1 
 axmov
 mov al,exp
 exp textequ %(30)					;redefining exp but no Error where as 
									;IN EQU its an Error
 axmov textequ < move bl,v1>		;redefining
 axmov
 mov al,exp
	
mov ah,04ch	
int 21h
end start
end