;Unsigned multiplication
;8 bit multiplication	A5 x 5A = 3A02
		
.model small
.stack 010h 
.data	
	M db 0A5h     ;8 bit multiplicand	
	Q db 5Ah	  ;8 bit multiplier
	Result dw 0

.code 
	mov ax,@data
	mov ds,ax
	mov ax,0	;Accumulator =0
	clc			;clear carry flag
	mov bl,M	;multiplicand to bl	
	mov dl,Q    ;multiplier    
	mov cx,8	;count=8 as 8-bit operation
	
L1:
	mov bh,dl	;Q to bh
	shr bh,1	;finding Q0 carry flag
	jnc noadd
	   ADD al,bl
	noadd:
		RCR al,1	
		RCR dl,1
		clc
Loop L1

	mov byte ptr [result+1],al
	mov byte ptr [result],dl

mov ah,04ch
int 021h

end
