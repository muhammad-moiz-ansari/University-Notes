;$ sign work & calculating **Imp***
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    v2 db 1,2    
    v2leng=$-v2
    check1=$
   ; check1 dd $        ; does not work
    v3 dw 1,2,3    
    v3leng=($-v3)/2
    check2=$
    v4 dd 1,2,3,4    
    v4leng=($-v4)/4
    check3=$
.code
main PROC
 mov eax,0
 mov esi,check1
 mov edi,check2
 mov eax,check3
 mov bl,v2leng
 mov cl,v3leng
 mov dl,v4leng 
 mov esi,$
 mov eax, offset v2
 mov al,[eax]

  mov eax,0
INVOKE ExitProcess,0
main ENDP
END main
 