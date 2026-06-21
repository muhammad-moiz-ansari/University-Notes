;Arry sort Bubble sort
;NO function

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
 ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
       data dw  3,2,1
       swap db  0	

.code
main PROC

Start:
	    mov swap,0       		 ;Reset swap flag to no swap 
        mov ebx,0                ;initialize array index to zero
loop1:
        mov ax,[ebx+data]        ;load number to ax
        cmp ax,[ebx+data+2]      ;compare with next number
        jbe noswap              ;no swap if already inorder

        mov dx,[ebx+data+2]      ;load second element in dx
        mov [ebx+data+2],ax      ;store first number in second
        mov[ebx+data],dx         ;store second number in first
        mov swap,1       		 ;flag that a swap has been done
noswap:
        add ebx,2              ;advance bx to next index
        cmp ebx,4              ;are we at last index 
        jne loop1               ;if not than compare next 2

        cmp swap,1      		 ;check if swap has been done
        je start                ;if yes than make another pass
             
		 INVOKE ExitProcess,0
    main ENDP
    END main