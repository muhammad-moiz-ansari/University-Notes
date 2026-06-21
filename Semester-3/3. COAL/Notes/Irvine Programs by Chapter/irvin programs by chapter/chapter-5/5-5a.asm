;Chapter 5 Procedures
; Practice NESTED PROCEDURE CALL

.model small
.stack 0100h
.data
.code

JMP main

sub1 proc
		
		l1:
		Push cx
		mov cx,3
		call sub2
		add ax,1
		pop cx
		LOOP l1			
	RET		
sub1 ENDP
;---------------------------------------	
sub2 proc				
		l1:
		Push cx
		mov cx,4
		call sub3
		add bx,1
		pop cx
		loop l1			
	RET		
sub2 ENDP
;---------------------------------------
sub3 proc		
		l1:		
			add dx,1		
		loop l1			
	RET		
sub3 ENDP
;---------------------------------------
main proc
	mov ax,@data
	mov ds,ax	
		mov ax,0
		mov bx,0
		mov dx,0
		mov cx,2
		call sub1
	main EndP	
	
mov ah,04ch
int 021h

end