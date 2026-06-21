;First program
.386				;for 386 does not run for x86
.model small
.stack 0100h
.data
	val1 db 4
		  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers	
	movzx ax,val1		  ; as val1 is byte size & ; will extend zeros
						  ; move	will extend  zeros in ah register 
	
end start
					
mov ah,04ch
int 021h
end