;sum ary content using recursion
;parameter passing through register
;sum return through ax register
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary1 db 1(ID1),2(ID2),3(ID3),4(ID4)   
.code
main PROC 
   mov eax,0
   mov edx,0
   mov ecx,sizeof ary1
   mov esi, offset ary1
   call sum
   mov eax,0
INVOKE ExitProcess,0
main ENDP
sum proc
    cmp ecx,0
    je exit
    
    add al,byte ptr[esi]
    inc esi
    dec ecx 
    call sum
    exit:
	inc edx
    ret
sum endp
END main