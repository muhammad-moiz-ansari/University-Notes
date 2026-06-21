;Chapter 8 Advance Procedures
; Practice LOCAL VARIABLES  passing value as reference 
;clear stack in RET

.model small
.stack 010h
.data	
	v1 db 5
	v2 db 6
.code

jmp start
;///////////////////////////////////////////
lvar proc
	push bp
	mov bp,sp
	mov ax,0
	sub sp,2			;creating local variable
	push si
	push ax
	mov ax,0
	mov si,[bp+4]			;accessing v2 address
	mov al,[si]				;Accessing value of v2
	mov [bp-2],ax			;storing v2 to local variable
	mov si,[bp+6]			;copying address of v1
	mov al,[si]				;creating copy
	xchg ax,[bp-2]			; xchg the value
	mov [si],al				;copying at 2nd parameter	
	mov si,[bp+4]
	mov ax,[bp-2]
	mov [si],al
	pop ax
	pop si
	mov sp,bp	
	pop bp
ret 4
lvar endp

start proc	
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov si,offset v1
	push si
	mov si,offset v2
	push si
	call lvar
	mov ax,0FFFFH
			
mov ah,04ch
int 021h
start endp
end

