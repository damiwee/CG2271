/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/
 
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "sound.h"
#include "motor.h"
#include "uart.h"
#include "led.h"

#define MASK(x)			(1 << (x))

#define RESTART				0b101010
#define	END					0b111111
#define STOP				0b0

#define MSG_COUNT   4

volatile uint8_t data = 0;
volatile int isEnd;
volatile int isMove;

osSemaphoreId_t uartDataSemaphore;
osMessageQueueId_t motorMsg;

typedef struct {
    uint8_t speed; 
    uint16_t dir;  
} myDataPkt;

/*----------------------------------------------------------------------------
 * IRQ
 *---------------------------------------------------------------------------*/

/* UART - handle receive interrupt */
void UART2_IRQHandler(void) {
	NVIC_ClearPendingIRQ(UART2_IRQn);
	if (UART2->S1 & UART_S1_RDRF_MASK) {
		data = (UART2->D);
		osSemaphoreRelease(uartDataSemaphore);
	}
}

/*----------------------------------------------------------------------------
 * tBrain thread
 *---------------------------------------------------------------------------*/

void tBrain(void *argument) {
	while (1) {
		osSemaphoreAcquire(uartDataSemaphore, osWaitForever);
			
		// Process received data
		//int speeds[4] = {0, 45, 75, 100};					// max duty cycle
		int speed, arg2;
		
		speed = data >> 6; // 2 most significant bits
		arg2 = (data & 0b00111111); // next 6 bits
		
		myDataPkt myData;
		
		
		if (speed != 0) {
			myData.speed = 100;
			myData.dir = arg2;
			osMessageQueuePut(motorMsg, &myData, NULL, 0);
			isMove = 1;
			isEnd = 0;
		}
		
		else if (arg2 == STOP) {
			myData.speed = 0;
			myData.dir = 0;
			osMessageQueuePut(motorMsg, &myData, NULL, 0);
			isMove = 0;
		}
		
		else if (arg2 == END) {
			myData.speed = 0;
			myData.dir = 0;
			osMessageQueuePut(motorMsg, &myData, NULL, 0);
			isMove = 0;
			// play coffin
			isEnd = 1;
		}
		
		else if (arg2 == RESTART) {
			myData.speed = 0;
			myData.dir = 0;
			osMessageQueuePut(motorMsg, &myData, NULL, 0);
			isMove = 0;
			// play audio1
			isEnd = -1;
		}
		
		else {
			myData.speed = 0;
			myData.dir = 0;
			osMessageQueuePut(motorMsg, &myData, NULL, 0);
			isMove = 0;
		}
	}
}

/*----------------------------------------------------------------------------
 * tMotorControl thread
 *---------------------------------------------------------------------------*/
void tMotorControl(void *argument){
	myDataPkt myRxData;
	
	for(;;) {
		osMessageQueueGet(motorMsg, &myRxData, NULL, osWaitForever);
		
		int maxSpeed = myRxData.speed;
		int direction = myRxData.dir;
		
		motorControl(maxSpeed, direction);
	}
}

/*----------------------------------------------------------------------------
 * tLed threads
 *---------------------------------------------------------------------------*/
void tLedGreen (void *argument) {
  for (;;) {
    if (isMove) {
      runningGreenLed();
    } else {
      allGreenLedLit();
    }
		
  }
}

void tLedRed (void *argument) {
  for (;;) {
    if (isMove) {
      flashRedLed(500);
    } else {
      flashRedLed(200);
    }
  }
}
/*----------------------------------------------------------------------------
 * tAudio thread
 *---------------------------------------------------------------------------*/
void tAudio(void *argument) {
	
	for(;;) {
		if (isEnd == 1) {
			playCoffin();
		}
		else if (!isEnd) {
			playPirates();
		}
		else {
			offAudio();
		}
	}
}

/*----------------------------------------------------------------------------
 * main
 *---------------------------------------------------------------------------*/
int main (void) {
 
  // System Initialization
  SystemCoreClockUpdate();
	initUART2();
	initPWM();
	initSoundPWM();
	initLed();
	offAllLed();
	
	isMove = 0;
	isEnd = -1;	
 
  osKernelInitialize();                 // Initialize CMSIS-RTOS
	
	uartDataSemaphore = osSemaphoreNew(1,0,NULL);
	
	motorMsg = osMessageQueueNew(MSG_COUNT, sizeof(myDataPkt), NULL);
	
	osThreadNew(tBrain, NULL, NULL);
	osThreadNew(tMotorControl, NULL, NULL);
	osThreadNew(tLedRed, NULL, NULL);
	osThreadNew(tLedGreen, NULL, NULL);
	osThreadNew(tAudio, NULL, NULL);
	
	osKernelStart();                      // Start thread execution
  for (;;) {}
}
