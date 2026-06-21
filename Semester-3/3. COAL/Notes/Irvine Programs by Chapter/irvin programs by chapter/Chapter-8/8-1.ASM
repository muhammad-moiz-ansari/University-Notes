;sum ary content using recursion
;parameter passing through register
;sum return through ax register
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    ary1 db 1,2    
.code
main PROC 
   mov eax,0
   
   call sum
  
   mov eax,0
INVOKE ExitProcess,0
main ENDP
sum proc
    
    ret
sum endp
END main