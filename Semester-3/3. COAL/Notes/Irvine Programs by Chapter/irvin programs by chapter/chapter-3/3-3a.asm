; Practice DATE DECLARATION
; QWORD
.model small
.stack 010h
.data			
	quad1 DQ 0123456789ABCDEFH
	quad2 QWORD -1
	quad3 QWORD 'AB'
	quad4 QWORD 2 DUP(012AB34CDh)	
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	MOV AX,OFFSET QUAD1				
mov ah,04ch
int 021h

end
