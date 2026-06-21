  .model small
.stack 0100h
.data
		list db 1,2,3,4
		list_size=4
		count=5
		n1 db count			;n1 goes to 5
		count=7
.code
start:
	 mov ax,@data
	 mov ds,ax
	 mov ax,0
	 mov al,n1      	;al =5 
	 mov bl,count		;bl=7
	 count='A'			;assembler convert its to number
	 mov cl,count		;cl=41
	
mov ah,04ch	
int 21h
end start
end