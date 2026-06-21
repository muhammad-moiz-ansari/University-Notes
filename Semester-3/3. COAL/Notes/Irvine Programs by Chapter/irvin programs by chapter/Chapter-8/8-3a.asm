;Chapter 8 Advance Procedures
; Practice LOCAL VARIABLES 
;clear stack in RET

.model small
.stack 0100h
.data
	val1 Dw 5
	val2 Dw 6	
.code
JMP Main

swap proc
	PUSH BP			
	mov bp,sp		
	sub sp,2				; creating space on stack for local variable
	push ax
	mov ax,[bp+4]
	mov [bp-2],ax			;saving parameter in local variable space
	mov ax,[bp+6]
	mov [bp+4],ax
	mov ax,[bp-2]
	mov [bp+6],ax
	pop ax
	mov sp,bp				;Removing space from stack created for local variable
	POP bp
	RET 4
swap ENDP

main proc
	mov ax,@data
	mov ds,ax
	Push val1		   		;sending parameters
	Push val2
	mov ax,10
	call swap			
main EndP	
	
mov ah,04ch
int 021h
end