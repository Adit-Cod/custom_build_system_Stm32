#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"

void USART2_Init(void);
void debugTraceInfo(char *msg);

#define TRACE_LOG_INFO(msg) debugTraceInfo(msg)
