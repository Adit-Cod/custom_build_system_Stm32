
/*1. Entry Point */
ENTRY(reset_Handler)

/*2. Memory Definitions */
MEMORY
{
FLASH(rx):ORIGIN =0x0800 0000, LENGTH = 512K
SRAM(rwx):ORIGIN =0x2000 0000, LENGTH = 128K
}
_estack = origin(SRAM) + LENGTH(SRAM)

/*3. Required Heap and Stack */
__max_heap_size  = 0x200
__max_stack_size = 0x400
 
/*4.  Sections */
SECTIONS
{

  .text :
  {
      *(.isr_vector_tbl)
	  *(.text)
	  *(.rodata) 
  }>FLASH	/* Here, you are pushing the above .text section onto the FLASH; that is the operation done here*/
  
  .data :
  {
     *(.data)
  }>SRAM AT > FLASH /*At runtime you would want the .data section to be available at the RAM; but the actual storage is in the Flash ; concept of VMA AND LMA */
  
}

