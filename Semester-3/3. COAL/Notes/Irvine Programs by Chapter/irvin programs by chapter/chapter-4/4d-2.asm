;OFFSET
; RETURN THE DISTANCE OF VARIABLE FROM THE BEGINNING OF ENCLOSED SEGMENT
.model small
.stack 0100h
.data
	 ary dw 10 dup(1)
	 pary1 dw ary            ;saving Address	  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	mov cx,ary
	
	mov si,offset ary      ;offset of ary
	mov si,pary
	

	
end start
					
mov ah,04ch
int 021h
end