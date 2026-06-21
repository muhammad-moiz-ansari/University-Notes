;LABEL DIRECTIVE
;LABEL Let you insert a label and give it size without allocating any space
.model small
.stack 0100h
.data
	v byte 0FFH
	val16 label word
	val8 label byte
	val dd 012345678h	
	v2 db 'AAA'
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,v
	;mov ax,val	   		 	;size miss match error
	;mov bx,word ptr val	
	;mov cl,byte ptr val	
	mov dl,val8
	mov si,val16	
end start
					
mov ah,04ch
int 021h
end