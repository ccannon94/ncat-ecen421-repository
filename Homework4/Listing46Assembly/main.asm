	.text
	.align 2
	.global main

main:

	;Bitfield instructions
	MOV R6, #0A12Fh; R6 = 0xA12F
	BFC R6, #8, #12; R6 = 0x2F
	SBFX R7, R6, #4, #8; R7 = 0x2

	;Packing and unpacking instructions
	MOV R8, #0AABBh; R8 = 0xAABB
	MOV R9, #0CCDh; R9 = 0xCCDD

	PKHBT R10, R8, R9, LSL #16; R9 = 0xCCDDAABB
	SXTH R11, R10, ROR #16; R10 = 0xFFFFCCDD

	;Misc instructions
	NOP
	DMB
	DSB
	MRS R12, APSR
	NOP

	.end
