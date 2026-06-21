;EQU associate a symbol name with an integer expression or some text 
.model small
.stack 0100h
	count = 100
	expr EQU 3-5+(2*(5-3))
	symbol EQU count	
	text EQU <10*10>
.data
	   v byte 0
	   ;string byte text    ;text macro nested level too deep
	   string2 WORD text
	   v2 byte 'AAA'
	   
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov bl,v
	mov al,expr
	mov cx,expr
	mov dx,text

end start
					
mov ah,04ch
int 021h
end