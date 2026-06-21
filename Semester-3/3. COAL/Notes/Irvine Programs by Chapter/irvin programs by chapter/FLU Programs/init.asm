;Finit

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  
.code
main proc
	
	mov eax,offset st1
	finit				;Set FPU control word to 037Fh
						;Sets (hides) all floating point exceptions
						;set rounding to nearest even
						;precision to 64 bit

	invoke ExitProcess,0
main endp
end main