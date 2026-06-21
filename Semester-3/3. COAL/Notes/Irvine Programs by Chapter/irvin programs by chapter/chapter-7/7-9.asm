;signed multiplication
;8 bit signed multiplication
;Booth algorithm
 
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    M db +13   	;Signed Multiplicand 8-bit
	Q db -5	  	;Signed Multiplier 8-bit
	A db 0		;Accumulator
	result dw 0		; Result A,Q
	Q_least db 0	;storing Q0 Q-1

.code
main PROC
	mov eax,0
	mov cx,8	;8-bit cx=8
	mov al,A	;al as accumlator
	mov bl,M	;bl as Multiplicand
	mov dl,Q 	;dl as multiplier
	clc			;Q-1 to zero
	
l1:	
	mov Q_least,dl	;copy dl to extract Q0
   	RCL Q_least,1	;Shift Q-1 in Q_least
	And Q_least,3	;Extracting Q0 and Q-1
	
	cmp Q_least,1	;if Q0 Q-1= 01
	jne skipadd			
	add al,bl		;A=A+M
    jmp shift
	
 skipadd:
	cmp Q_least,2	;if Q0 Q-1= 10
	jne shift
	sub al,bl		;A=A-M
 shift:				;if Q0 Q-1= 00/11
	SAR al,1		;Shift Arithmetic right
	RCR dl,1
	
LOOP L1
	mov byte PTR result, dl
	mov byte PTR result+1,al

   mov eax,0
INVOKE ExitProcess,0
main endp
END main