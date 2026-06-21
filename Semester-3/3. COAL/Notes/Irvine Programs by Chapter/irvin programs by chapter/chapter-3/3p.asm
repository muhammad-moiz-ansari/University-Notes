;First program
.model small
.stack 0100h
.data
	   
	   v byte 5
	   v1 byte 10 
	   selfpointer word $	; SAVING CURRENT ADDRESS IN SELFPOINTER
	   v2 byte 15  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov al,v
	mov ax,selfpointer
end start
					
mov ah,04ch
int 021h
end