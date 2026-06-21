;LABEL DIRECTIVE
;LABEL Let you insert a label and give it size without allocating any space
.model small
.stack 0100h
.data
	wptrv label word 
	v1 byte 2
	v2 byte 4
	
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,v1
	;mov ax,val	   		 	;size miss match error
	mov bx,word PTR v1
	mov cx,wptrv
		
end start
					
mov ah,04ch
int 021h
end