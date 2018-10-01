	.text
	.align 2

MemAddr .field 0x20000040; Memory address
BitBandAddr .field 0x22000810; Bit-band address

	.global main

main:

	;Data moving instructions
	MOV R0, #09h; RR0 = 0x09
	MOV R1, #11d; R1 = 0x0B
	MOV R2, #00001010b; R1 = 0x0A

	;Memory access instructions
	LDR R3, MemAddr;
	STR R2, [R3];
	STR R1, [R3, #4]!;
	LDR R0, [R3];

	PUSH {R3}
	POP {R4}

	;Bit-band operation
	LDR R5, BitBandAddr
	LDR R6, [R5]
	MOV R6, #1
	STR R6, [R5]

	;Forever loop
	B $

	.end
