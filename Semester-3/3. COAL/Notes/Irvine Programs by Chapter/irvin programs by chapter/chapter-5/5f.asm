;Chapter 5 Procedures
; Practice REVERSING STRING

.model small
.stack 0100h
.data
	string1 BYTE "Computer Organization & Assembly language",0
	len_str1= ($-string1)-1

.code	
	start:	
	mov ax,@data
	mov ds,ax	
	mov cx,len_str1
	mov si,OFFSET string1
	L1:
		mov ax,0
		mov al,[si]
		inc si
		PUSH ax	
	LOOP L1

	mov cx,len_str1
	mov si,OFFSET string1
	
	L2:
			mov ax,0
			pop ax
			mov [si],byte PTR al
			inc si			
	LOOP L2
	end start
mov ah,04ch
int 021h

end
