;Chapter 8 Advance Procedures
;PRACTICE: Recursion 
;PROGRAM:  FACTORIAL complete book

.model small
.stack 0100h
.data
.code
JMP Main
fact proc
	PUSH Bp
	mov bp,sp
	mov ax,[bp+4]
	cmp ax,0
	ja l1	
	mov ax,1
	jmp l2
	mul bx
	L1:	dec ax
	push ax
	call fact	
	return:	mov bx,[bp+4]
	mul bx	
	l2:		pop bp
	RET 2
fact ENDP
main proc
	mov ax,@data
	mov ds,ax
	mov ax,0
	PUSH CX 
	PUSH DX
	PUSH AX
	mov ax,2
	push ax
	call fact			
main EndP	
	
mov ah,04ch
int 021h
END