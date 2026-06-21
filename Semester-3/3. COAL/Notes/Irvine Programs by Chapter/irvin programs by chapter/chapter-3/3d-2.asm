.model small
.stack 010h
.data
	   string1 db 'abc'				
	   string2 db "ABC"
	   string3 db '123456'				;Ascii of 123
	   string4 db 'ABC"abc"ABC'			;commos ascii saved
	   string5 db "it's testing"		;' Ascii special 
	   string6 db "it,s testing"
	   
	   
.code
	mov ax,@data		   
	mov ds,ax
	mov ax,0       ; zeroing ax registers
	mov al,string1
					
mov ah,04ch
int 021h
END

end