; Practice JMP   LOOP NESTED

.model small
.stack 010h
.data
	List1 BYTE 1,2,3,4
		  BYTE 5,6,7,8
		  BYTE 9,10,11,12		 
	List2 DB 10, 041h ,'A', 00111111b	
	string BYTE 'ABC',0
	string2 BYTE "abc",0		
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov dx, offset list1
	mov al, LIST1
	mov bl, LIST2
					
mov ah,04ch
int 021h

end
