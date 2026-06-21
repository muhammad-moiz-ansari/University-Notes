;Chapter 8 Advance Procedures
; Practice ADD SUM PROG Passing parameters through stack
;clear stack in RET

.model small
.stack 0100h
.data
	val1 Dw 5
	val2 Dw 6
.code
JMP START
sum proc
		PUSH BP
		mov bp,sp
		mov ax,0
		add ax,[bp+4]
		add ax,[bp+6]
		POP bp
		RET 4					;Std window calling convention
sum ENDP
START:
	mov ax,@data
	mov ds,ax	
	main proc
		Push val1			;sending parameters
		Push val2
		call sum
	main EndP	
mov ah,04ch
int 021h

end