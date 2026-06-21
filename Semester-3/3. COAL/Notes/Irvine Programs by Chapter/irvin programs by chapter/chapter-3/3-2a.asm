
; Practice DATE DECLARATION
; WORD

.model small
.stack 010h

.data
	word1 DW 1
	word2 DW -1
	word3 SWORD -1
	word4 SWORD +1	
	List1 WORD 01F2BH,01101011001011b, 45
	list2 DW 10,2
	list3 WORD 3 DUP(0)		;DUP allocate storage for multiple data items 	
	list4 WORD 2 DUP(0AB12H)
	list5 DW 2 DUP(?)
	list6 DW 3 DUP('AB')
	
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov ax,word1
	
	
				
mov ah,04ch
int 021h

end
