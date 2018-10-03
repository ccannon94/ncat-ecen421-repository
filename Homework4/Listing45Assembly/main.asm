	.text
	.align 2
	.global main

main:
	MOV R5, #05h; R5 = 9x95
	MOV R6, #06h; R6 = 0x06
	MOV R7, #07h; R7 = 0x07
	BL Replace;

	B $;

Replace:
	MOV R4, R7
	MOV R7, R6
	MOV R6, R5
	MOV R5, R4
	BX LR

	.end
