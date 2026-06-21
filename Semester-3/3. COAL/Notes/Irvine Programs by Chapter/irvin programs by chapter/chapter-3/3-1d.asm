;\ line continuation character 
;concatenates two source code lines into a single statement.
.386
.model flat, stdcall     ; for protected mode
.stack 0100h
ExitProcess PROTO,dwExitCode:DWORD    ;window service
.data
    v1 \
    db \					;line continuation character
    "hello hi",0dh,0ah
    byte "hi again"
.code
main PROC
 mov eax,0
 mov al,\			;;line continuation character 
 [v1]
 mov eax,0 
   INVOKE ExitProcess,0
main ENDP
END main
 