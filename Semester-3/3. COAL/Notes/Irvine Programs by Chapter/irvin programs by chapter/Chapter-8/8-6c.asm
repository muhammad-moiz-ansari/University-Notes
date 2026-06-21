;Arry sort Bubble sort
;parameter passing through registers
;

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary db  6,ID1,ID2,ID3,ID4,1
.code
main PROC 
   mov eax,0
   mov ebx,0  
   push offset ary
   push lengthof ary
   call sort
   mov eax,0
INVOKE ExitProcess,0
main endp


SORT PROC
push ebp
mov ebp,esp
sub esp,4						  ;creating local variable
mov ecx,[ebp+8]
Start:
       mov esi,[ebp+12]
	   mov dword ptr[ebp-4],0     ;Reset local variable to no swap
       mov edi,1
        
loop1:
        mov al,[esi]            ;load number to ax
        cmp al,[esi+1]          ;compare with next number
        jbe noswap              ;no swap if already inorder

        mov dl,[esi+1]           ;load second element in dx
        mov [esi+1],al           ;store first number in second
        mov [esi],dl              ;store second number in first
        mov dword ptr[ebp-4],1       		 ;flag that a swap has been done
noswap:
        add esi,1              ;advance bx to next index
        inc edi
        cmp edi,ecx
        jne loop1              ;if not than compare next 2

        cmp dword ptr[ebp-4],1      		 ;check if swap has been done
        je start                             ;if yes than make another pass
        mov esp,ebp							;distroying local variable
        pop ebp
    ret 8
    SORT ENDP

END main
