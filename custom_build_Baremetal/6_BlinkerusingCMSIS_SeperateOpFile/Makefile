cc  = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=out/stm32_blinker.map
build: prereq out/stm32_blinker.elf

prereq: 
	mkdir out

out/main.o : main.c
	$(cc) $(CFLAGS) main.c -o out/main.o
	
out/startup_stm32f446re.o : startup_stm32f446re.c 
	$(cc) $(CFLAGS) startup_stm32f446re.c -o out/startup_stm32f446re.o
	
out/stm32_blinker.elf : out/main.o out/startup_stm32f446re.o
	$(cc) $(LDFLAGS) $^ -o $@

flash :
	openocd -f board/st_nucleo_f4.cfg
	
clean :
	cd out && \
	del -f *.o *.elf *.map && \
	cd .. && \
	rmdir out