;bubble sort
;parameter pass through array
;local variable
;swapfunction

.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary db 3,2,-1
.code
SORT PROC
push ebp
mov ebp,esp
sub esp,4
mov ecx,[ebp+8]
dec ecx
Start:
       mov esi,[ebp+12]
	   mov dword ptr[ebp-4],0       		 ;Reset swap flag to no swap
       mov ebx,0
        
loop1:
        mov al,[esi+ebx]            ;load number to ax
        cmp al,[esi+ebx+1]          ;compare with next number
        jbe noswap              ;no swap if already inorder

        mov dword ptr[ebp-4],1        ;flag that a swap has been done
        mov edi,esi
        add edi,ebx
        push edi
        call SWAP    
        
noswap:                     
        inc ebx                 ;advance bx to next index
        cmp ebx,ecx
        jne loop1              ;if not than compare next 2

        cmp dword ptr[ebp-4],1      		 ;check if swap has been done
        je start                             ;if yes than make another pass
        mov esp,ebp
        pop ebp
    ret 8
    SORT ENDP
SWAP proc
        push ebp
        mov ebp,esp
        push esi
        mov esi,[ebp+8]
        mov dl,[esi+1]           ;load second element in dx
        mov [esi+1],al           ;store first number in second
        mov [esi],dl              ;store second number in first
        pop esi 
        pop ebp           
ret 4
SWAP endp
main PROC 
   mov eax,0
   mov ebx,0  
   push offset ary
   push lengthof ary
   call sort
   mov eax,0
INVOKE ExitProcess,0
main endp
END main