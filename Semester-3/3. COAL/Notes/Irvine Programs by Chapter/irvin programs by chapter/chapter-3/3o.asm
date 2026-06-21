;= associate a symbol name with an integer 
.model small
.stack 0100h
.data
	   v byte 0
	   count=5
	   esc_key=27
	   list db count dup(?)
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,count
	count=15
	mov al,count
end start
					
mov ah,04ch
int 021h
end