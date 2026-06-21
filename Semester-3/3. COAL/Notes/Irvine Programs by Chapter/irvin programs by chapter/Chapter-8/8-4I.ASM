;ary sum program
;parameter passing through stack
;register saving on stack
;return in eax
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary1 db 1(ID1),2(ID2),3(ID3),4(ID4)
.code
main PROC 
   mov eax,0
   push dword ptr offset ary1
   push dword ptr sizeof ary1
   mov esi,1
   mov ecx,2
   mov ebp,3
   call sum
   mov eax,0
INVOKE ExitProcess,0
main endp

sum proc
    push ebp
    mov ebp, esp
    push esi
    push ecx
    mov esi,[ebp+12]
    mov ecx,[ebp+8]
    cmp ecx,0
    je exit
    
	add al,byte ptr[esi]
	inc esi
	dec ecx
	
	push esi
	push ecx
	call sum
	exit:
    pop ecx
    pop esi
    pop ebp
    ret 8
sum endp
END main
