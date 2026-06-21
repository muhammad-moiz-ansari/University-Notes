;JMP Instruction   ;unconditional jmp
.model small
.stack 0100h
.data
	
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	jmp Label1
	mov ax,2
	add ax,2
	inc ax

Label1:
	mov bx,2
	add bx,2
	inc bx
	
end start
					
mov ah,04ch
int 021h
end