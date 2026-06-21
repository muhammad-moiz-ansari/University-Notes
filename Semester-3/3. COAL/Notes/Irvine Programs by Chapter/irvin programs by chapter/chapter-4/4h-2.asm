;length return number of elements in an array
.model small
.stack 0100h
.data
	val1 word 10h,20h,30H
		 word 11h,12h,13h
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov ax,val1
	mov ax,val1+8
	mov ax,lengthof val1   ; 3		
	
end start
					
mov ah,04ch
int 021h
end