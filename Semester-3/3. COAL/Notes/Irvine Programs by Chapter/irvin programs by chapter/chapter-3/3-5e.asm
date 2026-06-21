.model small
.stack 0100h
.data
	
	firstoffset dw $		; store first offset of data segment
	list1 db 1,2,3,4
	list1size= $-list1
	list2 dw 1,2,3,4
	list2size= ($-list2)/2
	list3 dd 1,2,3,4
	list3size= ($-list3)/4
.code
start:
 mov ax,@data
 mov ds,ax
 mov ax,0
 mov ah,list1
 mov bh,list1size
 mov cx,list2
 mov dh,list2size
 mov dh,list3size
 mov si,$
	
mov ah,04ch	
int 21h
end start
end