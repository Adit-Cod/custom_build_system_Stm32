
target : stm32_blinker.elf

main.o : main.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o main.o
	
startup_stm32f446re.o : startup_stm32f446re.c 
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 startup_stm32f446re.c -o startup_stm32f446re.o
	
stm32_blinker.elf : main.o startup_stm32f446re.o
	arm-none-eabi-gcc -nostdlib -T stm32_ls.ld *.o -o stm32_blinker.elf -Wl,-Map=stm32_blinker.map

load :
	openocd -f board/st_nucleo_f4.cfg
	
clean :
	del -f *.o *.elf *.map