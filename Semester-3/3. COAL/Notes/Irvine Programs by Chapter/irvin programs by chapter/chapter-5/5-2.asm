;Chapter 5 Procedures
;PUSHF
; Practice PUSHFD  //not supported in 16 bit 

.model small
.stack 0100h
.data
	Wval1 WORD 0FFFFH
	saveFlag WORD 0	
.code	
		mov ax,@data
		mov ds,ax
		mov ax,0
		mov ax,Wval1
		add ax,1
		PUSHF				;16 -bit store flag register
		;POP BX
		;pushfd				;32 bit flag register to stack
		;popfd
		POP saveflag		;Cannot use mov instruction to get value of flag register
							;value to other register/or to memory
							;Push Flag & pop to local could be used
		mov bx,saveFlag
		PUSHF
		mov cx,0FFFFH
		add cx,1			; will update flag register
		POPF				;Restore value saved on stack to flag register
		
			
mov ah,04ch
int 021h

end
