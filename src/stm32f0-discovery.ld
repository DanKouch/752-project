MEMORY
{
	rom (rx) : ORIGIN = 0x08000000, LENGTH = 128K
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}

EXTERN (vector_table)
EXTERN (output_dk)

ENTRY(reset_handler)

SECTIONS
{
	.text : {
		*(.vectors)	/* Vector table */
		*(.text*)	/* Program code */
		/usr/lib/gcc/arm-none-eabi/*(.text)
		. = ALIGN(4);
	} >rom
	.ram : {
		. = ALIGN(4);
	} >ram
	
	end = .;
}

