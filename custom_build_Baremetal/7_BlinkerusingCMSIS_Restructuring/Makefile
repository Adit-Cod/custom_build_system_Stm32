cc  = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=out/stm32_blinker.map
BUILD_DIR = out
build: prereq ${BUILD_DIR}/stm32_blinker.elf

prereq: 
	mkdir out

${BUILD_DIR}/main.o : src/main.c
	$(cc) $(CFLAGS) src/main.c -o ${BUILD_DIR}/main.o
	
${BUILD_DIR}/startup_stm32f446re.o : src/startup_stm32f446re.c 
	$(cc) $(CFLAGS) src/startup_stm32f446re.c -o ${BUILD_DIR}/startup_stm32f446re.o
	
${BUILD_DIR}/stm32_blinker.elf : ${BUILD_DIR}/main.o ${BUILD_DIR}/startup_stm32f446re.o
	$(cc) $(LDFLAGS) $^ -o $@

flash :
	openocd -f board/st_nucleo_f4.cfg
	
clean :
	cd ${BUILD_DIR} && \
	del -f *.o *.elf *.map && \
	cd .. && \
	rmdir out