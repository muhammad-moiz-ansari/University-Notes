
; Practice DATE DECLARATION
; TWORD
;PACKED BCD

.model small
.stack 010h

.data	
	word2 DW -1
	list1 BYTE 1,2
	quad1 DQ 0123456789ABCDEFH
	List2 DB 10, 041h ,'A', 00111111b
	string BYTE 'ABC',0
	list4 WORD 2 DUP(0AB12H)	
	quad3 QWORD 'AB'
		
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov ax,OFFSET word2	
				
mov ah,04ch
int 021h

end
