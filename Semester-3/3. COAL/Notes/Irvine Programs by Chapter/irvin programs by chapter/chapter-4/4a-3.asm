;LAHf   
;SAHF				** not storing value of ah to flag
.model small
.stack 0100h
.data
	val1 db 4 
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	add cl,0FFH
	LAhF 				  ; Load Flag to AH register	
	mov ah,0FFH
	SAHF				  ;FF not store flage register instead D7 stored
	
end start
					
mov ah,04ch
int 021h
end