;Arry sort Bubble sort
;parameter passing through registers
;working perfect
;all register push in function 

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary db 6,5,4,3,2,1
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
sub esp,4
push esi
push ebx
push ecx
push eax
mov esi,[ebp+12]        ;offset of array
mov ecx,[ebp+8]         ;size of array
dec ecx
Start:       
	   mov dword ptr[ebp-4],0       		 ;Reset swap flag to no swap
       mov ebx,0        
loop1:
        mov al,[esi+ebx]            ;load number to ax
        cmp al,[esi+ebx+1]          ;compare with next number
        jbe noswap                  ;no swap if already inorder

        mov ah,[ebx+esi+1]           ;load second element in dx
        mov [ebx+esi+1],al           ;store first number in second
        mov [esi+ebx],ah             ;store second number in first
        mov dword ptr[ebp-4],1       ;flag that a swap has been done        
noswap:                     
        inc ebx                      ;advance bx to next index
        cmp ebx,ecx
        jb loop1              ;if not than compare next 2

        cmp dword ptr[ebp-4],1      ;check if swap has been done
        je start                    ;if yes than make another pass
        pop eax
        pop ecx
        pop ebx
        pop esi
        mov esp,ebp
        pop ebp
    ret 8
    SORT ENDP
END main

