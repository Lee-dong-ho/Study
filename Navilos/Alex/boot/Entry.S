# Entry.S
.text
	.code 32

	.global vecto_start
	.global vector_end

	vector_start:
		MOV R0, R1
	vector_end:
		.space 1024, 0
.end
