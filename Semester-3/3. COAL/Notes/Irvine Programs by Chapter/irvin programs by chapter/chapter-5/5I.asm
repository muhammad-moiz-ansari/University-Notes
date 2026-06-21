	;Chapter 5 Procedures
; Practice NESTED PROCEDURE CALL

.model small
.stack 0100h
.data
.code

JMP START

sub1 proc		
		add ax,1
		call sub2
		add bx,1
	RET		
sub1 ENDP
;---------------------------------------	
sub2 proc				
		add ax,1
		call sub3
		add bx,1
	RET		
sub2 ENDP
;---------------------------------------
sub3 proc		
		add ax,1
		call sub3
		add bx,1
sub3 ENDP
;---------------------------------------
START:
		
	mov ax,@data
	mov ds,ax	
	
	main proc
		mov ax,0
		mov bx,0
		call sub1
		add cx,1
	main EndP	
	
mov ah,04ch
int 021h

end