#include "MKL25Z4.h"                    // Device header
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"

typedef enum {LOW, HIGH} value_t;

extern volatile int isMove;

void initLed(void);
void offAllLed(void);
void offGreenLed(void);
void offRedLed(void);
void toggleOnOffLed(GPIO_Type *gpio, uint8_t pin);
void runningGreenLed(void);
void allGreenLedLit(void);
void flashRedLed(uint16_t time);
