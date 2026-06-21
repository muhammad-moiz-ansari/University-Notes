; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	  st1 word 0FFFFH
      x real4 +9.0625
	  y real4 -0.333
	  result real4 0.0
	  en word 0AAAAH
.code
main proc
	
	mov eax,offset st1
	finit
	FLD x				;Load to st(0)
	FLD y				;Load to st(0)
	FADD ST(0),ST(1)
	FST result


	invoke ExitProcess,0
main endp
end main