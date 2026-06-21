;Unsigned multiplication
;16 bit multiplication	A5 x 5A = 3A02
		
.model small
.stack 010h 
.data	
	M dw 01A1Ah   ;16 bit multiplicand	
	Q dw 05a5ah	  ;16 bit multiplier
	acc dw 0
	Result dd 0

.code 
	mov ax,@data
	mov ds,ax
	clc			;clear carry flag
	mov bx,M	;multiplicand to bl	
	mov dx,Q    ;multiplier    
	mov cx,16	;count=16 as 16-bit operation
	
L1:
	mov ax,dx	;Q to bh
	shr ax,1	;finding Q0 carry flag
	jnc noadd 
	   ADD acc,bx
	noadd:
		RCR acc,1	
		RCR dx,1
		clc
Loop L1
	mov ax,acc
	mov word ptr [result+2],ax
	mov word ptr [result],dx

mov ah,04ch
int 021h

end
