;movsx

; *** NOT RUN ON DEBUGGER******
.386				;*****for 386 does not run on pwb****
.model small
.stack 0100h
.data
	val1 db 4
		  
.code
	start:
	mov ax,@data		   ;
	mov ds,ax
	mov ax,0               ; zeroing ax registers
	
	movsx ax,val1		  ; as val1 is byte size & 
						  ;move	will extend sign bit in least byte
						  ; zero extention performed by default
	mov val1,80h
	movsx ax,val1		; One extention performed
						 
	
end start
					
mov ah,04ch
int 021h
end