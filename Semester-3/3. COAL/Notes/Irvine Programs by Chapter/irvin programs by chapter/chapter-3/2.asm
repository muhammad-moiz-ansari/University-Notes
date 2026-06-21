.model small
.stack 0100h
.data 	
	val1 db 3*2
.code
	mov ax,5*6+3+'a'
	mov bl,val1
	add ax,bx

mov ah,04ch
int 021h

end

.386
.model flat, stdcall
.stack 0100h

ExitProcess PROTO,dwExitCode:DWORD
.data

.code
main PROC

   mov ax,1
   mov bx,2
   mov cx,3
   mov dx,4

	
   INVOKE ExitProcess,0
main ENDP
END main