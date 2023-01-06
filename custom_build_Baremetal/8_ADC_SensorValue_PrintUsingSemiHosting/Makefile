BUILD_DIR = out
cc  = arm-none-eabi-gcc 
CFLAGS = -c -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -std=gnu11
LDFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32_ls.ld -Wl,-Map=${BUILD_DIR}/stm32_adc.map


build: prereq ${BUILD_DIR}/stm32_adc.elf

prereq: 
	mkdir out

${BUILD_DIR}/main.o : src/main.c
	$(cc) $(CFLAGS) src/main.c -o ${BUILD_DIR}/main.o

${BUILD_DIR}/ADC_Driver.o : src/ADC_Driver.c
	$(cc) $(CFLAGS) src/ADC_Driver.c -o ${BUILD_DIR}/ADC_Driver.o
	
${BUILD_DIR}/startup_stm32f446re.o : src/startup_stm32f446re.c 
	$(cc) $(CFLAGS) src/startup_stm32f446re.c -o ${BUILD_DIR}/startup_stm32f446re.o
	
${BUILD_DIR}/stm32_adc.elf : ${BUILD_DIR}/main.o ${BUILD_DIR}/startup_stm32f446re.o ${BUILD_DIR}/ADC_Driver.o
	$(cc) $(LDFLAGS) $^ -o $@

flash :
	openocd -f board/st_nucleo_f4.cfg
	
clean :
	cd ${BUILD_DIR} && \
	del -f *.o *.elf *.map && \
	cd .. && \
	rmdir out