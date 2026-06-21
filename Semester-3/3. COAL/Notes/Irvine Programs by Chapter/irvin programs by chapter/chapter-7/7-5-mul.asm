; Practice multiplication algorithm from VU handout

;Shift Left
			
.model small
.stack 010h
.data
	multiplier db 5
	multiplicand db 13
	result db 0
.code 
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov al,multiplier
	mov bl,multiplicand
	mov cx,4
	
	l1:
		Shr al,1
		jnc shiftonly
		
		add result,bl		
	shiftonly:
		Shl bl,1	
	Loop l1
	
mov ah,04ch
int 021h

end
