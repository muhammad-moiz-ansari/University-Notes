; Practice DATE DECLARATION
;BYTE, DUP
.model small
.stack 010h
.data	
	;DUP allocate storage for multiple data items 
	;Used to allocate space for string or arrays
	
	list1 BYTE 1,2
	list2 BYTE 3 DUP(2,0)	 ;Duplicate (2,0)	three times in Memory
	list3 DB 2 DUP(?,1)
	list4 BYTE 2 DUP(0ABH)
	list5 BYTE 3 DUP('AB')
		
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	MOV AL,LIST1				
mov ah,04ch
int 021h
end
