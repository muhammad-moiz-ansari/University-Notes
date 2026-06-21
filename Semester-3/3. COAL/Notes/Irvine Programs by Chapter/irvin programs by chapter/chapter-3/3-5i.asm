
; Practice INDIRECT ADDRESSING : Register Contain address of Data

.model small
.stack 010h
.data
		SUN	EQU	<"Sunday",0>
		MON	EQU	<"Monday",0>
		TUE	EQU	<"Tuesday",0>
		WED	EQU	<"Wednesday",0>
		THU	EQU	<"Thursday",0>
		FRI	EQU	<"Friday",0>
		SAT	EQU	<"Saturday",0>
		NUMBER_OF_DAYS = 7
		var1 db 5
		weekdays	BYTE	SUN,MON,TUE,WED,THU,FRI,SAT		

.code
main proc	
    mov ax,@data
	mov ds,ax
	mov ax,0
	mov bl, var1

	
main endp
end main


	
mov ah,04ch
int 021h
end


