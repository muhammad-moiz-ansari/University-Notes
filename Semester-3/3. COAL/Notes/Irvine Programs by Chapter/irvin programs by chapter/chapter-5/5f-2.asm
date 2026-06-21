;Chapter 5 Procedures
; Practice PUSHFD  //not supported in 16 bit 

.model small
.stack 0100h
.data
	Wval1 WORD 0FFFFH
	saveFlag WORD 0	
.code
		start:
		
		mov ax,@data
		mov ds,ax
		mov ax,0
		mov ax,Wval1
		add ax,1
		PUSHF				;store flag register
		POP saveFlag		;Cannot move flag Register value to other register/or to memory
							;Push Flag & pop to local could be used
		mov bx,saveFlag
		PUSHF
		mov cx,0FFFFH
		add cx,1		; will update flag register
		POPF			;Restore value saved on stack to flag register
		end start
		
			
mov ah,04ch
int 021h

end
