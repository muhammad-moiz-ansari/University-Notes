; Practice Integer Arithmetic

;Shift Left
.386			
.model small
.stack 010h
.data
	val1 word 59h
.code 
	mov ax,@data
	mov ds,ax
	mov ax,59h
	shl al,2				;shift with immediate
	
	
	

mov ah,04ch
int 021h

end
