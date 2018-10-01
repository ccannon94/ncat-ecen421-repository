	.text
	.align 2
	.global main

main:

	;Arithmetic operation instructions
	MOV R0, #09h; R0 = 0x09
	MOV R1, #11d; R1 = 0x0B
	MOV R2, #00001010b; R1 = 0x0A

	ADD R3, R0, R1; R3 = R0 + R1 = 0x14
	SUB R4, R2, #0002h; R4 = R2 - 0x02 = 0x08
	MOV R5, R2; R5 = R2
	MUL R5, R0; R5 = R5 * R0 = 0x5A
	SDIV R6, R5, R1; R6 - R5 / R1 = 0x08

	;Logic operation instructions
	MOV R0, #09h; R0 = 0x09
	MOV R1, #11d; R1 = 0x0B
	MOV R2, #00001010b; R1 = 0x0A

	AND R3, R0, R1; R3 = R0 + R1 = 0x14
	ORR R4, R1, #0002h; R4 = R2 - 0x02 = 0x08
	EOR R5, R0, R2; R5 = R2
	LSL R6, R0, #2; R5 = R5 * R0 = 0x05A
	LSR R7, R0, #2; R5 = R5 * R0 = 0x5A

	;Saturating arithmetic instructions
	MOV R0, #0FFFFh; R0 = 0x0000FFFF
	MOVT R0, #7FFFh; R0 = 0x7FFFFFFF
	MOV R1, #0FFFFh; R1 = 0x0000FFFF
	MOVT R1, #7FFFh; R1 = 0x7FFFFFFF

	ADDS R2, R1, R0; R2 = 0xFFFFFFFE, overflow
	QADD R3, R1, R0; R3 = 0x7FFFFFFF, saturation

	;Forever loop
	B $

	.end
