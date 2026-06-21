;length return number of elements in an array
.model small
.stack 0100h
.data
	val1 db 10,20,30
	val2 dw 30 dup(0),0,0,0
	val3 dw 3 dup(3 dup(0)) 
	val4 dd 3,4,5
	val5 byte '1234567',3,4,5	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cl,val1
	mov al,lengthof val1
	mov al,lengthof val2
	mov al,lengthof val3
	mov al,lengthof val4
	mov al,lengthof val5
	
	
	
end start
					
mov ah,04ch
int 021h
