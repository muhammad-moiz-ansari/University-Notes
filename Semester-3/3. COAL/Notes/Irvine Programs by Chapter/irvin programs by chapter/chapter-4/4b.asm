;xchg
.model small
.stack 0100h
.data
	val1 db 4
	val2 dw 5
	val3 db 7
	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0ABCDH
	mov bx,01234H
	xchg ax,bx			   ;register to register xchg
	
	mov cl,255
	xchg cl,val1			   ; register to Memory	
	
	;mov val1,val3			;ERROR invalid instruction operands Mem to mem 
	
	mov ax,0
	mov al,val1				;mem to mem xchg
	xchg val3,al
	mov val1,al
	
	;xchg cx,5			   ;ERROR invalid instruction  register to const exchange	
	
end start
					
mov ah,04ch
int 021h
end