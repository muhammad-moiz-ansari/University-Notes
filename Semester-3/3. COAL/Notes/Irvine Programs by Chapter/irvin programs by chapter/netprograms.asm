;LINK:   https://gist.github.com/dumpmycode/87fc003152d83b2b91bf0f245ae6a776
;Swap elements in array, e[0] with e[1], e[2] with e[3] and so on. Need to read more on faster xchg instruction, xor?
	var dd 1,2,3,4,5,6,7,8
		mov esi, OFFSET var
		mov ecx, LENGTHOF var / 2       ; processing 2 elements at one time
	xchgloop:
       		mov eax, DWORD PTR [esi]        ; eax=1
        	xchg eax, DWORD PTR [esi+4]     ; put 1 in esi+4 and put [esi+4] in eax
       		mov DWORD PTR [esi], eax        ; put [esi+4] in esi+0
        	add esi, TYPE var * 2           ; move to next 2 elements
        	loop xchgloop
Sum the gaps in array
	var dd 0,2,5,9,10
        	mov esi, OFFSET var
		mov ecx, LENGTHOF var - 1 
   	xchgloop:
		mov edx, [esi]			; edx = 0
		add esi, TYPE var		; esi+4
		sub edx, [esi]			; 0 - 2 = -2
		neg edx				; -2 becomes 2
 		add eax, edx			; sum to eax
		loop xchgloop
Turn 16bit array to 32bit array
	var WORD 1,2,5,9,10
    	var2 DWORD LENGTHOF var DUP(0)		; init array with 0
		mov edi, OFFSET var2
		mov esi, OFFSET var
		mov ecx, LENGTHOF var		; load loop counter
    	loopy:
		movzx eax, WORD PTR [esi]	; store first 16bit element to register, zero extend
		add esi, TYPE var		; esi + 2, move to next 16bit array element
		mov DWORD PTR [edi], eax	; write value to new 32bit array
		add edi, TYPE var2		; index to next element in 32bit array
		loop loopy
Fibonacci numbers
	n BYTE 5
	fib BYTE 1,1,?,?,?,?,?
		mov esi, OFFSET fib
		movzx ecx, BYTE PTR [n]
	loopy:
		movzx edx, BYTE PTR [esi]		; load 1st seed to edx
		mov eax, edx
		add esi, TYPE fib			; move index 1 element forward
		movzx edx, BYTE PTR[esi]		; add 2nd seed to 1st seed
		add eax, edx
		add esi, TYPE fib			; move index 1 element forward
		mov [esi], eax
		sub esi, TYPE fib			; go back 1 element
		loop loopy	
Reverse array
	revArr BYTE 99h,88h,77h,66h,55h,44h,33h,22h,11h,00h
		mov edi, LENGTHOF revArr - 1		; index counter going backward
		mov esi, OFFSET revArr			; array address
		mov ecx, LENGTHOF revArr / 2		; operate 2 array elements at a time
	loopy:
		mov al, BYTE PTR [esi]			; mov first element to al
		mov bl, BYTE PTR [esi+edi]		; mov last element to bl
		mov BYTE PTR [esi], bl			; write last element to first array position
		mov BYTE PTR [esi+edi], al		; write first element to last array position
		inc esi					; move to next element to swap
		sub edi, 2				; move to second last element to swap
		loop loopy				; edi-2 because esi also moves forward by 1 so its balanced.
Copy string in reverse
	source BYTE 'This is the source string', 0		; '0' is also counted when using SIZEOF 26bytes
	destination BYTE SIZEOF source DUP ('#')
		mov esi, OFFSET source
		mov edi, OFFSET destination
		mov ecx, LENGTHOF source - 1			; dont reverse null terminating str in array
	loopy:							; reverse string per char, ignoring null terminating byte 
		mov al, BYTE PTR [esi + (ecx - 1)]		; ecx=25 -> [esi+25], last char index in dest, excl. null str
		mov BYTE PTR [edi], al				; write on destination[0]
		add edi, 1					; move to next dest index
		loop loopy	
		mov BYTE PTR [edi], 00h				; restore null terminating string to array
Shift element in array
	source WORD 1,2,3,4,5,6
		mov esi, OFFSET source
		mov edi, OFFSET source
		mov ecx, LENGTHOF source - 1			
	loopy:							; n-1 operation, need improvement
		mov ax, WORD PTR [edi+TYPE source]		; save 2nd arrelement in reg
		mov bx, WORD PTR [esi]				; save 1st element in reg
		mov WORD PTR [esi], ax				; swap 2nd & 1st
		add edi, TYPE source				; move to next index
		mov WORD PTR [edi], bx				; finish swap proc
		loop loopy
Chapter 5

Linking Array Items - Use start as seed index, then use index array value to locate next char to write.
	start = 1
	chars BYTE 'H','A','C','E','B','D','F','G'
	index DD 0,4,5,6,2,3,7,0
	newarray BYTE SIZEOF chars DUP ('x')

		mov esi, OFFSET chars			
		mov edi, OFFSET newarray		
		mov edx, start					; load first seed index
		mov ecx, DWORD PTR LENGTHOF chars		; load counter to iterate all characters
	loopy:								
		movzx eax, BYTE PTR [esi+edx]			; load first char to write to
		mov BYTE PTR [edi], al				; new array according to seed index
		mov edx, index[type index * edx]		; use index value as next index
		add edi, TYPE newarray				; move to next index of newarray
		loop loopy
Simple Addition (Clear screen, move cursor to middle and sum 2 int inputs).
	INCLUDE Irvine32.inc
	prompt	BYTE 'Enter two integers and I will add them.',0dh, 0ah,0
	int1	BYTE 'Integer 1: ',0
	int2	BYTE 'Integer 2: ',0
	rows	BYTE ?
	cols	BYTE ?
	two	= 2
	index	BYTE 0,1,2,3,4
	
		mov ecx, 3
	loopy:
		call Clrscr
		mov esi, OFFSET index
		mov eax, LENGTHOF prompt
		shr eax, 1				; find half length of string, use to center text on screen
		mov cols, al

		call LocXY
		mov edx, OFFSET prompt			; string addr as param in edx
		call WriteString			; display prompt

		call LocXY
		mov edx, OFFSET int1
		call ReadInt				; get int input #1, returns in eax
		mov ebx, eax				; save result

		call LocXY
		mov edx, OFFSET int2
		call ReadInt				; get 2nd input

		call LocXY
		add ebx, eax
		mov eax, ebx
		call WriteInt				; display result

		call Crlf
		call LocXY
		call WaitMsg
		loop loopy

		invoke ExitProcess, 0
	main endp                  
               
	LocXY PROC					; locate cursor to middle
		push eax
		push edx
		xor eax, eax
		xor edx, edx
		call GetMaxXY				; no input, returns: AX = rows, DX = cols
		movzx eax, al				; only take low 8bit since max is 255
		shr al, 2				; divide row / height by 2, inaccuracy of 1 col / row is negligible
		add al, [esi]				; print next line
		shr dl, 1				; divide col / width by 2
		sub dl, cols				; start writing index half of text to center it
		mov dh, al				; insert row parameter for Gotoxy, col parameter is correct in dl
		call Gotoxy
		add esi, TYPE index			; center the text
		pop edx					; restore eax, edx values
		pop eax
		ret
	LocXY ENDP

	end main
BetterRandomRange
count DWORD ?					; sum of random numbers generated in array
numArray DWORD 22 DUP ('xxxx')			; max array space, max index range counted using variable count
upperB DWORD ?
lowerB DWORD ?
loopCounter DWORD ?

main proc
	call Randomize
	mov ecx, 50
	loop50:
		mov eax, 100; upper boundary
		mov ebx, -300; lower boundary
		call BetterRandomRange				
		call WriteInt
		call Crlf
		loop loop50
	call WaitMsg
	Invoke ExitProcess, 0
main endp

BetterRandomRange proc				; generate a list of 2 - 22 random numbers and randomly choose 1
	mov DWORD PTR [loopCounter], ecx
	lea esi, numArray
	
	mov edx, eax
	call RangeLoop				; process upper boundary, eax already set
	
	mov DWORD PTR [count], 0		; clear count loop
	mov eax, ebx				; process lower boundary
	mov edx, eax
	call RangeLoop			

	mov eax, count				; pick random number from array of random numbers
	call RandomRange
	mov eax, numArray[eax * TYPE numArray]
	mov ecx, DWORD PTR[loopCounter]
	ret
BetterRandomRange endp


RangeLoop proc					; Generate range of random numbers and pick one. input : eax, output : eax
	test eax, eax				; do negative random number generation using neg instructions
	jns PositiveRange
	
	NegativeRange:
		call Random10
		mov ecx, eax
		add DWORD PTR[count], eax			
	
		loopN: 
		mov eax, edx
		neg eax
		call RandomRange
		neg eax	
		mov DWORD PTR [esi], eax
		add esi, TYPE numArray
		loop loopN
		jmp exitRangeLoop

	PositiveRange:				; do positive range calculation							
		call Random10
		mov ecx, eax
		add DWORD PTR[count], eax			

		loopP:
		mov eax, edx
		call RandomRange		; store random numbers in stack
		mov DWORD PTR[esi], eax
		add esi, TYPE numArray
		loop loopP

	exitRangeLoop:
	ret
RangeLoop endp


Random10 proc					; generate random number 1 - 11 input: eax, ouput : eax
	mov eax, 10
	call RandomRange
	add eax, 1					
	ret
Random10 endp

end main
Recursive Procedure. Count how many times program executes, using ecx as recursive depth limit.
INCLUDE Irvine32.inc
counter BYTE ?
prompt BYTE 'Recursion counter: ',0

main proc
	mov ecx, 10
	call recProc
	call printResult
	INVOKE ExitProcess, 0
main endp

recProc proc					; recursion using loop only, no conditional jumps.
	add BYTE PTR [counter], 1
	loop L1
	ret
	L1:
		call recProc
recProc endp

printResult proc USES eax edx			; print counter results
	mov edx, OFFSET prompt
	call WriteString
	movzx eax, BYTE PTR[counter]
	call WriteDec
	call Crlf
	call WaitMsg
	ret
printResult endp
Fibonacci Generator using recursion, return point mangled, manually restore with esp adjustment
INCLUDE Irvine32.inc
N = 47
fibArr DWORD 1, 1, N-2 DUP('xxxx')		; minus 2 for the first two seeds (1,1)

main proc					; N=47, fibonacci generator, N as number length. array pointer & N as input
	mov esi, OFFSET fibArr
	mov ecx, N-1								
	call fibo
	INVOKE ExitProcess, 0
main endp

;==================================
fibo proc
; fibonacci generator with seed 1, 1.
; input: esi-ptr array, ecx counter
; returns: none, it writes to array ptr given at input

	loop L1
	add esp, 4*(N-2)			; restore return point of first function call once loop is exhausted
	ret
	L1:
		mov eax, DWORD PTR[esi]
		add eax, [esi + 4]
		mov DWORD PTR[esi + 8], eax
		add esi, 4
		call fibo
fibo endp
;==================================

end main
Calculate grades 0-100
.data
prompt BYTE 'Score: ',0
grade BYTE 'Grade: ',0

.data?
score BYTE ?

.code
main proc
	call Randomize
	mov ecx, 100
	
	L1:
		mov eax, ecx
		mov BYTE PTR [score], al
		call calcGrade
		call printResult
		sub ecx, 1
		jnz L1

	call WaitMsg
	INVOKE ExitProcess, 0
main endp

;================================
; calcGrade 
; Grades a signed integer input and returns a single capital letter as score grade
; INPUT: eax
; RETURNS: al - single capital letter
;================================
calcGrade proc
	
	test eax, eax			; check if grade 0 - 59
	jz gradeF
	cmp eax, 59
	jle gradeF

	cmp eax, 60				
	jz gradeD
	cmp eax, 69
	jle gradeD

	cmp eax, 70
	jz gradeC
	cmp eax, 79
	jle gradeC

	cmp eax, 80
	jz gradeB
	cmp eax, 89
	jle gradeB

	cmp eax, 90
	jge gradeA

	gradeF:
		mov eax, 'F'
		jmp done
	gradeD:
		mov eax, 'D'
		jmp done
	gradeC:
		mov eax, 'C'
		jmp done
	gradeB:
		mov eax, 'B'
		jmp done
	gradeA:
		mov eax, 'A'
	done:
	ret
calcGrade endp

printResult proc
	mov edx, OFFSET grade
	call WriteString
	call WriteChar
	call Crlf

	mov edx, OFFSET prompt
	call WriteString
	movzx eax, BYTE PTR [score]
	call WriteInt
	call Crlf

	call Crlf
	ret
printResult endp

end main
Boolean calculator
INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data
X = 00001111b
Y = 00000101b

caseTable	BYTE '1'				
		DWORD OFFSET proc1
entrySize = ($ - caseTable)				; size = 5 (1byte + 4bytes)
		BYTE '2'
		DWORD OFFSET proc2
		BYTE '3'
		DWORD OFFSET proc3
		BYTE '4'
		DWORD OFFSET proc4
		BYTE '5'
		DWORD OFFSET done
numEntry = ($ - caseTable) / entrySize
prompt		BYTE '1. x AND y', 0dh, 0ah				
		BYTE '2. x OR y', 0dh, 0ah					
		BYTE '3. NOT x', 0dh, 0ah					
		BYTE '4. x XOR y', 0dh, 0ah					 
		BYTE '5. Exit program', 0dh, 0ah
		BYTE 'Enter your selection (1-5): ', 0
strAND		BYTE ' AND ', 0
strOR		BYTE ' OR ', 0
strNOT		BYTE ' NOT ', 0
strXOR		BYTE ' XOR ', 0

.data?

.code
main proc
	mov esi, OFFSET caseTable
	mov edx, OFFSET prompt
	call WriteString
	call ReadChar
	call WriteChar
	mov ebx, 1
L1:
	cmp al, BYTE PTR [esi]			; compare input to first element in caseTable, call function if correct
	jnz next
	call Crlf
	call printBins
	mov eax, X
	call DWORD PTR [esi+1]
	jmp finish
next:
	add esi, entrySize
	jmp L1
finish:
	call WaitMsg
	INVOKE ExitProcess, 0
main endp

proc1 proc USES edx ebx
	mov edx, OFFSET strAND
	call WriteString
	call Crlf
	AND eax, Y
	call WriteBinB
	call Crlf
	ret
proc1 endp
	
proc2 proc USES edx ebx
	mov edx, OFFSET strOR
	call WriteString
	call Crlf
	OR eax, Y
	call WriteBinB
	call Crlf
	ret
proc2 endp

proc3 proc USES edx ebx
	mov edx, OFFSET strNOT
	call WriteString
	call Crlf
	NOT eax
	call WriteBinB
	call Crlf
	ret
proc3 endp

proc4 proc USES edx ebx
	mov edx, OFFSET strXOR
	call WriteString
	call Crlf
	XOR eax, Y
	call WriteBinB
	call Crlf
	ret
proc4 endp

printBins proc USES eax ebx
	mov eax, X
	mov ebx, 1
	call WriteBinB
	call Crlf
	mov eax, Y
	call WriteBinB
	ret
printBins endp

done proc
	exit
done endp
end main
Text with random colors, having a feel for conditional jumps instead of loop directive / table driven selection method.
COMMENT # Generate 20 lines of text, each line colored with probability:
white	= 30%, 2 - 4 = 15
blue	= 10%, 1 = 9
green	= 60%, 5 - 10 = 2
eax SetTextColor
#

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data
prompt BYTE 'This is text colored with White(30%), Green(60%) or Blue(10%) probability.',0dh,0ah,0

.data?

.code
main proc
	call Randomize
	mov ecx, 20

begin:
	call rand10
	cmp eax, 1
	jnz not1
	mov eax, 9				; if eax = 1, set color to white & print text
	call SetTextColor
	call printText
	sub ecx, 1
	jnz begin
	jmp finished

not1:
	cmp eax, 5
	jge more5
	jmp less5

less5:						; eax = 2-4, use white(15)
	mov eax, 15
	call SetTextColor
	call printText
	sub ecx, 1
	jnz begin
	jmp finished

more5:						; eax= 5 or greater, use green(2)
	mov eax, 2
	call SetTextColor
	call printText
	sub ecx, 1
	jnz begin

finished:
	mov eax, 15				; restore normal text color
	call SetTextColor
	call WaitMsg
	INVOKE ExitProcess, 0
main endp

rand10 proc
	mov eax, 10				; generate random number 1-10
	call RandomRange
	add eax, 1			
	ret
rand10 endp

printText proc USES edx
	mov edx, OFFSET prompt
	call WriteString
	ret
printText endp

end main
Simple xor encryption
.data
pText BYTE "You cannot read this because it is encrypted.",0dh, 0ah, 0
pLen = ($ - pText) - 3			; minus 1 for null string, 2 for /r/n
keyX BYTE 'A9Xmv#7'
kxLen = ($ - keyX)

.code
main proc
	xor eax, eax
	mov esi, OFFSET pText
	mov edi, OFFSET keyX
	mov ecx, pLen
	mov ebx, kxLen

	mov edx, esi
	call WriteString
	call xorCrypt
	call WriteString

	call WaitMsg
	INVOKE ExitProcess, 0
main endp

xorCrypt proc USES edx ebx esi edi
begin:
	mov al, BYTE PTR [esi]		; xor pText[0] with keyX[0] and overwrite pText[0] with result
	XOR al, BYTE PTR [edi]		; overwrite OK because xor crypt can be reversed
	mov BYTE PTR [esi], al
	add esi, 1
	add edi, 1
	sub ecx, 1
	test ecx, ecx
	jz finish			; if ecx = 0, we have encrypted all letters in pText. finish.
	sub ebx, 1
	jnz begin			; if ebx != 0, we have not used all letter in key so loop back to beginning
	mov edi, OFFSET keyX		; if ebx = 0, cycle the key again and reset the ebx counter
	mov ebx, kxLen
	jmp begin

finish:
	ret
xorCrypt endp

end main
PIN validator
COMMENT *Validate PIN using specified int range for each PIN.
1st PIN must be between 5 - 9
2nd PIN must be between 2 - 5
3rd PIN must be between 4 - 8
4th PIN must be between 1 - 4
5th PIN must be between 3 - 6
- Generate 10 random 5 digit PIN 
- Check each pin digit according their range
- Display if they are valid/invalid, colored to red(4) if invalid, green(2) if valid next to the PIN
- White(15)
*

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data?
PINarray BYTE 5 DUP (?)

.data
validStr	BYTE ' is valid PIN', 0dh, 0ah, 0	
invalidStr	BYTE ' is invalid PIN', 0dh, 0ah, 0
rangeTable	BYTE '5'				; set range lookup table mapped to ecx counter 
		DWORD OFFSET digitRange1
rangeSize = ($ - rangeTable)
		BYTE '4'
		DWORD OFFSET digitRange2
		BYTE '3'
		DWORD OFFSET digitRange3
		BYTE '2'
		DWORD OFFSET digitRange4
		BYTE '1'
		DWORD OFFSET digitRange5
tableEntries = ($ - rangeTable) / rangeSize

.code
main proc						
	call Randomize
	mov ecx, 1000
	loopy:
		mov esi, OFFSET PINarray
		mov edi, OFFSET rangeTable
		call genRanPIN			
		call validatePIN
		call writeResult
		sub ecx, 1
		jnz loopy
	call WaitMsg
	INVOKE ExitProcess, 0
main endp

;===================================
; writeResult - print colored valid/invalid string depending on input
; INPUT:	[eax] 1 = invalid, 0 valid
; Returns:	None
;===================================
writeResult proc USES eax
	mov edx, OFFSET PINarray
	call WriteString
	test eax, eax				; check if eax = 0 (valid) or 1 (invalid)
	jnz invalid
	mov eax, 2				; set green text color
	call SetTextColor
	mov edx, OFFSET validStr
	call WriteString
	jmp finish
	invalid:
		mov eax, 4			; set text color to red
		call SetTextColor
		mov edx, OFFSET invalidStr
		call WriteString
	finish:
	mov eax, 15				; restore text to white
	call SetTextColor
	ret
writeResult endp

;===================================
; validatePIN - validates PIN set
; INPUT:	[esi] ptr to array initialised with random digits
;		[edi] range table pointer
; Returns:	[eax] 0=valid, 1=invalid
;===================================
validatePIN proc USES esi ebx ecx
	mov ecx, LENGTHOF PINarray
	digitloop:
		call DWORD PTR [edi+1]		; call function to set N-th digit range
		call validateDigit		; validate digit using supplied range
		test eax, eax
		jnz finish			; eax = 1, invalid digit, exit
		add esi, TYPE PINarray		; move to next random pin
		add edi, rangeSize		; move to next ecx mapped range table 
		sub ecx, 1
		jnz digitloop
	finish:
	ret
validatePIN endp

;====================================
; validateDigit - validates a digit to supplied low/high range
; INPUT: [bl] low range, [bh] high range, [esi] array ptr
; Returns: [eax] 0=valid, 1=invalid
;====================================
validateDigit proc USES ebx esi
	mov al, BYTE PTR [esi]
	cmp al, bl			; check if less than low range
	jl invalid
	cmp al, bh			; check if greater than high range
	jg invalid
	mov eax, 0			; al is bigger than low range, less than high range (valid)
	jmp finish
	invalid:
		mov eax, 1
	finish:
		ret
validateDigit endp

;====================================
; genRan10 - generate random number between 1-9
; INPUT: None
; OUTPUT: [eax] random number 1-9
;====================================
genRan10 proc
	mov eax, 9
	call RandomRange
	add eax, 1
	ret
genRan10 endp

;====================================
; genRanPIN - write 5 random number to suppiled uninitialised array
; INPUT: [esi] ptr to un-init array
; Returns: none, write pin to array
;====================================
genRanPIN proc USES eax ecx esi
	mov esi, OFFSET PINarray
	mov ecx, LENGTHOF PINarray
	pinloop:
		call genRan10
		add al, 48			; convert to ascii letter so it is printable
		mov BYTE PTR[esi], al		; fill the 5 digit array
		add esi, 1
		sub ecx, 1
		jnz pinloop
		ret
genRanPIN endp

;====================================
; digitRange1 - set acceptable range for 1st digit
; INPUT: None
; Returns: [bh] high range, [bl] low range
;====================================
digitRange1 proc
	mov bl, 35h
	mov bh, 39h
	ret
digitRange1 endp

; ====================================
; digitRange2 - set acceptable range for 2nd digit
; INPUT: None
; Returns: [bh] high range, [bl] low range
; ====================================
digitRange2 proc
	mov bl, 32h
	mov bh, 35h
	ret
digitRange2 endp

; ====================================
; digitRange3 - set acceptable range for 3rd digit
; INPUT: None
; Returns: [bh] high range, [bl] low range
; ====================================
digitRange3 proc
	mov bl, 34h
	mov bh, 38h
	ret
digitRange3 endp

; ====================================
; digitRange4 - set acceptable range for 4th digit
; INPUT: None
; Returns: [bh] high range, [bl] low range
; ====================================
digitRange4 proc
	mov bl, 31h
	mov bh, 34h
	ret
digitRange4 endp

; ====================================
; digitRange5 - set acceptable range for 5th digit
; INPUT: None
; Returns: [bh] high range, [bl] low range
; ====================================
digitRange5 proc
	mov bl, 33h
	mov bh, 36h
	ret
digitRange5 endp

end main
Parity checker / population counter / Hamming weight. Need to include parallel alg in.
COMMENT *Count the parity of 10byte array
eax = 0 (false) even parity
eax = 1 (true) even parity
*

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data?
paritySum BYTE ?
numBits DWORD ?

.data
val1 DWORD 0000000fh

.code
main proc			
	xor ebx, ebx
	mov eax, DWORD PTR [val1]
	mov ecx, 32

	jmp BrianKalgorithm

	linear:					; this checks every LSB = 1 or 0 then bit shift right and repeat 
	test eax, 1				; if bit = 0, move to next bit
	jz bitNotset
	add ebx, 1				; bit is set, add counter
	bitNotset:				; no zero, shr 1, loop
	shr eax, 1				; move next bit to inspection slot
	sub ecx, 1
	jnz linear
	jmp linearfin
		
	notSolinear:				; like linear but exit early if left side bits are all 0
	test eax, 1				; if LSB = 0, move to next bit
	jz moveOn
	add ebx, 1				; bit is set, add population counter
	moveOn:						
	shr eax, 1				; move next bit to inspection slot
	jz notSolinearfin			; check if eax = 0, true = quit
	jmp notSolinear				; ecx loop counter not needed because it will exit on eax = 0

	BrianKalgorithm:
	test eax, eax				; check if eax = 0, true = quit
	jz BKfin			
	mov edx, eax				
	sub edx, 1				; by sub 1, it will reverse the right side bits
	AND eax, edx				; x & (x-1) removes most right bit
	add ebx, 1				; add population counter
	jmp BrianKalgorithm			; repeat

	BKfin:
	linearfin:
	notSolinearfin:

	AND ebx, 1
	jz itsEven
	mov eax, 0
	jmp finallyFin
	itsEven:
	mov eax, 1
	finallyFin:
	call WaitMsg
	INVOKE ExitProcess, 0
main endp

end main
Generate prime number from 2-1000 using Sieve of Eratosthenes method.
COMMENT *Generate prime number using Sieve of Eratosthenes
ranging from 2-1000 and display all prime values
*

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

N = 1000

.data?
soeArray WORD (N/2)+1 DUP(?)			; cut half since fillArray proc skips even number. 

.data

.code
main proc		
	xor eax, eax
	xor ebx, ebx
	mov esi, OFFSET soeArray
	mov ecx, N
	call fillArray
	mov ecx, LENGTHOF soeArray + 1
	loopy:
		sub ecx, 1
		jz fin
		add esi, 2
		mov ax, WORD PTR [esi]
		test ax, ax
		jz loopy			; ax = 3
		mov dx, ax			; ax will get clobbered from nPower2, save to bx
		call nPower2			; ax = 9
		cmp ax, N
		jg fin				; ax^2 > N, means prime factoring complete
		mov ax, dx			; restore ax
		call primeChecker
		jmp loopy
	fin:
		mov esi, OFFSET soeArray			
		call printResult
	call WaitMsg
	INVOKE ExitProcess, 0
main endp

;======================================
; printResult
; INPUT: [esi] array ptr, [bx] index counter
; Returns: None
;======================================
printResult proc USES esi ebx
	mov ecx, LENGTHOF soeArray
	begin:
		mov ax, WORD PTR [esi]
		test ax, ax
		jz skipNext			; if zero skip printing.
		call WriteInt
		call Crlf
	skipNext:
		add esi, 2
		sub cx, 1
		jnz begin
	ret
printResult endp

;======================================
; primeChecker - Need improvement to check if divisible starting from eax*eax
; INPUT: [ax] first element to check, [esi] ptr array, [cx] counter
; Returns: None
;======================================
primeChecker proc USES eax ebx ecx edx esi
	mov bx, ax				; set divisor
	begin:
		add esi, 2					
		mov ax, WORD PTR [esi]
		test ax, ax
		jz notComposite			; current array element = 0, skip checks to next element
		xor dx, dx			; prep for div
		div bx
		test dx, dx			; if number not composite, move on to next element
		jnz notComposite			
		mov WORD PTR [esi], 00h		; if number composite, change to NULL
	notComposite:
		sub ecx, 1
		jnz begin
	ret
primeChecker endp

; ======================================
; nPower2 - N to the power of 2 e.g.N*N, 4 * 4, 5 * 5 etc by addition. (3 * 3 = 3 + 3 + 3, 4 + 4 + 4 + 4 and so on)
; INPUT: [ax] N / base number
; Returns: [ax] result
; ======================================
nPower2 proc USES ebx ecx
	xor bx, bx
	mov cx, ax
	begin :
		add bx, ax		; add 3 to ax 3 times
		sub cx, 1
		jnz begin
		mov ax, bx
	ret
nPower2 endp

;======================================
; Fill array for Sieve of Eratosthenes exercise 
; INPUT: [esi] ptr to array, [ecx] N max range
; Returns: none. Supplied undefined array ptr will be initialised with numbers.
;======================================
fillArray proc USES eax esi ecx
	mov ax, 2
	mov WORD PTR[esi], ax
	loopy:
		test ax, 1		; dont need to fill array with even num other than 2
		jz dontPrintEven
		cmp ax, N		; dont go over max limit N
		jg fin
		add esi, 2
		mov WORD PTR[esi], ax
	dontPrintEven:
		add ax, 1
		sub cx, 1
		jnz loopy
	fin:
	ret
fillArray endp
end main
GCD/GCF - Greatest common divisor/factor using supplied algorithm
COMMENT * Implement pseudo code below, call it 5x with different input
	
	int GCD (int x, int y) {
		x = abs(x)                  // absolute value
		y = abs(y)
		do {
			int n = x % y
			x = y
			y = n
		} while (y > 0)
		return x
	}
*

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data?

.data

.code
main proc		
	call Randomize	
	mov ecx, 5
	testLoop:
		call rand50
		call WriteInt
		call Crlf
		mov ebx, eax
		call rand50
		call WriteInt
		call Crlf
		call gcd
		call WriteInt
		call Crlf
		sub ecx, 1
		jnz testloop

	call WaitMsg
	INVOKE ExitProcess, 0
main endp

;===============================
; GCD - find largest common divisor between 2 integer
; INPUT: [eax] is X, [ebx] is Y
; Returns: [eax] greatest common divisor
;===============================
gcd proc USES ebx ecx edx
	mov ecx, ebx
	loopy:
		xor edx, edx
		div ebx			; N[edx] = X % Y
		test edx, edx		; while(y>0)
		jz fin
		mov eax, ebx		; X = Y
		mov ebx, edx		; Y = N
		sub ecx, 1		
		jnz loopy
	fin:
		mov eax, ebx		; return gcd 
	ret
gcd endp

rand50 proc 
	mov eax, 50
	call RandomRange
	add eax, 1
	ret
rand50 endp

end main
Bitwise multiplication using addition & bit shift. http://users.utcluj.ro/~baruch/book_ssce/SSCE-Shift-Mult.pdf
COMMENT * Bitwise Multiply - multiply any unsigned 32bit integer to [eax] using shifting & addition only
pass 32bit integer input to [ebx] and return in [eax]
*

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data?

.data

.code
main proc		
	mov eax, 7
	mov ebx, 7
	call bitMul

	call WaitMsg
	INVOKE ExitProcess, 0
main endp

;======================
; bitMul - bitwise multiplication using shifting / addition only
; INPUT: [ebx] unsigned 32bit int input multiplicand
; Returns: [edx:eax] unsigned int output, [edx] high bits [eax] low bits
;=======================
bitMul proc
	mov ecx, 32
	xor edx, edx			; A = 0
	start:
		test eax, 1		; check if LSB = 1
		jz shiftR
		add edx, ebx		; A += B
	shiftR:
		shr edx, 1		; edx:eax pair needs to shift (together) as one 
		jnc noCarry		; if CY=1, add it to MSB [eax]
		rcr eax, 1
		jmp fin
	noCarry:
		shr eax, 1
	fin:
		sub ecx, 1
		jnz start
	ret
bitMul endp
end main
Print chessboard on screen with alternating colors.
COMMENT *Draw 8x8 chess board with alternating gray/white square
use SetTextColor & Gotoxy from Irvine library
avoid the use of global variable
use declared parameters in all procedures
use short procedures that are focused on single task
white = 15
gray = 7
*

INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

.data?

.data

.code
main proc		
	push ebp
	mov ebp, esp
	sub esp, 2
	mov BYTE PTR [ebp-1], 0			; black color
	mov BYTE PTR [ebp-2], 15		; white color
	xor edx, edx
	mov ecx, 16
	begin:	
		call Gotoxy
		call printBoard
		add BYTE PTR [ebp-1], 1		; cycle through all 16 colors
		mov eax, 500
		call Delay
		sub ecx, 1
		jnz begin
	mov esp, ebp
	pop ebp
	call WaitMsg
	INVOKE ExitProcess, 0
main endp

; ==========================
; printBoard - print alternating colored chess board
; INPUT: none
; OUTPUT: none
; ==========================
printBoard proc USES ecx edx
	mov ecx, 8
	L1:
		call swapColor
		call printBlocks		; print a colored blocks
		add dh, 4			; move cursor to next row
		call Gotoxy
		sub ecx, 1			; change color and print blocks until it forms a line
		jnz L1
	ret
printBoard endp

; ==========================
; printBlocks - print a line of 8 colored blocks
; color & cursor position must be set before calling this proc
; INPUT: none
; OUTPUT: none
; ==========================
printBlocks proc USES ecx edx
	mov ecx, 8
	L2:
		call print1block		; cursor back at 0,0 row,col
		add dl, 8			; move to next column 
		call Gotoxy
		call swapColor			; swap color every block printed
		sub ecx, 1
		jnz L2
	ret
printBlocks endp

; ==========================
; print1block - print a line of colored blocks to make a solid 8x4 block
; color & cursor position must be set before calling this proc
; INPUT: none
; OUTPUT: none
; ==========================
print1block proc USES ecx edx
	mov ecx, 4
	L3:
		call printLine			; print colored lines until it forms a square block on screen
		add dh, 1			; move next row
		call Gotoxy
		sub ecx, 1
		jnz L3
	ret
print1block endp

;==========================
; printLine - print a line of colored blocks
; color & cursor position must be set before calling this proc
; INPUT: none
; OUTPUT: none
;==========================
printLine proc uses eax ecx
	mov ecx, 8
	mov eax, 219
	L4:
		call WriteChar			; colored block
		sub ecx, 1
		jnz L4
	ret
printLine endp

;=========================
; swap color - swap color in stack frame
;=========================
swapColor proc USES eax ebx
	mov al, BYTE PTR[ebp - 1]
	mov ah, BYTE PTR[ebp - 2]
	mov BYTE PTR[ebp - 1], ah
	mov BYTE PTR[ebp - 2], al
	movzx eax, ah
	call SetTextColor
	ret
swapColor endp

end main