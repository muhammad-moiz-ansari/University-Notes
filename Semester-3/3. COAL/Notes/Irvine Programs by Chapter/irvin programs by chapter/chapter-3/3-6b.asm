
; Practice DATE DECLARATION
; TWORD
;PACKED BCD

.model small
.stack 010h

.data	
	
	b1 Byte 'AB'
	w1 WORD 'AB'
	d1 DWORD 'AB'
	q1 QWORD 'AB'
		
.code
	mov ax,@data
	mov ds,ax
	mov ax,0
	mov ax,OFFSET b1
	
	
				
mov ah,04ch
int 021h

end
