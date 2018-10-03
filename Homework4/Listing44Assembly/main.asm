	.text
	.align 2
	.global main

main:

	;if else
	MOV R4, #05h; R4 = 0x05
	CMPS R4, #06h;
	BHS Greater; Branch if higher or same
	AND R4, #-1; R4 = R4 - 1
	B Done1
Greater:
	ADD R4, #1; R4 = R4 + 1
Done1:

	;for
	MOV R4, #0Ah; R4 = 0x0A
Loop1:
	ADDS R4, #-1; R4 = R4 - 1
	BPL Loop1

	;while
	MOV R4, #0006h; R4 = 0x06
	MOV R5, #0002h; R5 = 0x02
Loop2:
	ADDS R4, #-1; R4 = 0x06
	CMPS R4, R5;
	BNE Loop2

	;forever loop
	B $

	.end
