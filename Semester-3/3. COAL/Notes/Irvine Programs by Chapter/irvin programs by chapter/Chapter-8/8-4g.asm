;Ary Sum
;parameter passing through stack
;
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary1 db 1,2,3,4    
.code
main PROC 
   mov eax,0
   push dword ptr sizeof ary1	;ary size
   push dword ptr offset ary1	;ary offset
   call sum
   mov eax,0
INVOKE ExitProcess,0
main endp

sum proc
    push ebp
    mov ebp, esp
    push esi
    push ecx
    mov esi,[ebp+8]
    mov ecx,[ebp+12]
   
    mov eax,0
    l1:
        add al,byte ptr[esi] 
        inc esi
    loop l1
    pop ecx
    pop esi
    pop ebp
    ret
sum endp
END main
