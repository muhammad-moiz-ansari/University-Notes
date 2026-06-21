.model small
.stack 010h
.data
	count1 equ 1
    count2=count1+count1
   ; count1=5    ;redefined not allowed with equ
   string1 equ "he"
   v1 dw string1
   val1 db count3
   count3=9
   count3=20
   string2 db \
   "a very long string of characters "	

.code
main proc	
    mov ax,@data
	mov ds,ax
	mov ax,0
	mov bl, var1

	
main endp
end main





