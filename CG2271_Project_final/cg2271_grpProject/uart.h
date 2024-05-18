#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"

#define UART_RX_PORTE23	23
#define UART2_INT_PRIO	128

void initUART2(void);
