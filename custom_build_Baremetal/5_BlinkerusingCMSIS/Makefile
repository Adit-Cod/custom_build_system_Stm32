cc  = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld *.o
target : stm32_blinker.elf

main.o : main.c
	$(cc) $(CFLAGS) main.c -o main.o
	
startup_stm32f446re.o : startup_stm32f446re.c 
	$(cc) $(CFLAGS) startup_stm32f446re.c -o startup_stm32f446re.o
	
stm32_blinker.elf : main.o startup_stm32f446re.o
	$(cc)  $(LDFLAGS) -o stm32_blinker.elf -Wl,-Map=stm32_blinker.map

load :
	openocd -f board/st_nucleo_f4.cfg
	
clean :
	del -f *.o *.elf *.map