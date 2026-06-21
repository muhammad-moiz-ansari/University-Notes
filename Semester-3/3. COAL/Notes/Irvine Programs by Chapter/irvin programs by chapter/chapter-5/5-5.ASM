	;Chapter 5 Procedures
; Practice ADD SUM PROG

.model small
.stack 0100h
.data
.code

JMP main
;...........Sum Procedures.............
sum proc
		add ax,bx     
		add ax,cx
		;jmp start:   ; inside proc you can only jump to a local labels 
RET
sum ENDP
;.......Main proc...................

main proc
		mov ax,@data
		mov ds,ax
		mov ax,1
		mov bx,2
		mov cx,3
		call sum
		mov bx,0
main EndP	
	
mov ah,04ch
int 021h

end