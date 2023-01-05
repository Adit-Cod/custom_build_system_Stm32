
/*1. Entry Point */
ENTRY(reset_Handler)

/*2. Memory Definitions */
MEMORY
{
   FLASH(rx):ORIGIN =0x08000000, LENGTH =512K
   SRAM(rwx):ORIGIN =0x20000000, LENGTH =128K
}
_estack = ORIGIN(SRAM) + LENGTH(SRAM);

/*3. Required Heap and Stack */
   /* These values can be changed as per application requirement */
__max_heap_size  = 0x200;
__max_stack_size = 0x400;
 
/*4.  Sections */
SECTIONS
{
/* First Section of Output File */
  .text :
  {
      . = ALIGN(4); /* Aligning the memory in packs of 4 byte = Word */
      *(.isr_vector_tbl)
	  *(.text)
	  *(.rodata)
	  . = ALIGN(4);
      _etext = .; /* Fetch the ending address of .text section */	  
  }>FLASH	      /* Here, you are pushing the above .text section onto the FLASH; that is the operation done here*/

/* Second Section of Output File */
  .data :
  {
    _sdata = .; 
	. = ALIGN(4);
	/* Capture the start address of the data section ; this is used for copying the data section onto RAM at Run time*/
    *(.data)
	. = ALIGN(4);
	_edata = .;
	
  }>SRAM AT > FLASH /*At runtime you would want the .data section to be available at the RAM; but the actual storage is in the Flash ; concept of VMA AND LMA */
 
/* Third Section of Output File */
  .bss :
  {
    _sbss = .; /* Track start address of .bss section    */
	. = ALIGN(4);
     *(.bss)   /* Merge all .bss sections of input files */
	. = ALIGN(4);
    _ebss = .; /* Track End Address of .bss section      */
  }>SRAM
}

