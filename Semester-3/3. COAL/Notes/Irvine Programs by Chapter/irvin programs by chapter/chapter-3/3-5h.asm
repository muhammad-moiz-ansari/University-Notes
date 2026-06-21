.model small
.stack 0100h
.data
	num1 db 0
	n1=2
	v1 EQU 2*n1
	v2 EQU <5*n1>
	n1=3
	ary db v1,v2,n1
.code
start:
 mov ax,@data
 mov ds,ax
 mov ax,0
 mov al,num1
 mov bl,ary
 mov cl,[ary+1]
 mov dl,[ary+2]
 mov al,[ary+3]
 
mov ah,04ch	
int 21h
end start
end