;Chapter 8 Advance Procedures
; Practice LOCAL VARIABLES  passing value as reference 
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
	push si
	mov si,[bp+4]			;moving address of val1
	mov [bp-2],si			;saving address at local variable
	mov si,[bp+6]			;moving address of val2 
	mov ax,word ptr si		;extracting value of val2
	mov si,[bp+4]			;moving address of val1
	mov word ptr si,ax		;saving ax value in address
	mov si,[bp-2]
	mov ax,word ptr si		;value of val 
	mov si,word ptr [bp+6]
	mov word ptr si,ax
	pop si
	pop ax
	mov sp,bp				;Removing space from stack created for local variable
	POP bp
	RET 4
swap ENDP

main proc
	mov ax,@data
	mov ds,ax
	mov si,OFFSET val1
	Push si		   			;sending parameters
	mov si,OFFSET val2
	Push si	
	mov ax,10				;value will be recovered on return
	call swap
			
main EndP	
	
mov ah,04ch
int 021h
END