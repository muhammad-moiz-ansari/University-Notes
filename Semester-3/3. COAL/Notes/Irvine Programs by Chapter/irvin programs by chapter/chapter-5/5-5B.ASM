;Chapter 5 Procedures
; Practice NESTED PROCEDURE CALL

.model small
.stack 0100h
.data
.code

JMP main

sub1 proc		
		l1:
		INC AX
		LOOP l1			
	RET		
sub1 ENDP

	
main proc
		
	mov ax,@data
	mov ds,ax	

		mov ax,0
		mov bx,0
		mov dx,0
		mov cx,2
		call sub1
		mov cx,2
		call sub1				;infinit loop as Cx not intialized again
	main EndP	
	
mov ah,04ch
int 021h

end