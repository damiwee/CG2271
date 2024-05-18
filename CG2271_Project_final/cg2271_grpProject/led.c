#include "Led.h"

#define MASK(x) (1 << (x))


uint8_t greenPinsB[] = {8, 9, 10, 11};
uint8_t greenPinsE[] = {2, 3, 4, 5};
uint8_t redPin = 21;


void initLed() {
  SIM->SCGC5 |= ((SIM_SCGC5_PORTB_MASK) | (SIM_SCGC5_PORTE_MASK));
  
	// Configure MUX settings to make all 3 pins GPIO
  for (uint8_t i = 0; i < 4; i++) {
    PORTB->PCR[greenPinsB[i]] &= ~PORT_PCR_MUX_MASK;
    PORTB->PCR[greenPinsB[i]] |= PORT_PCR_MUX(1);
    
    PORTE->PCR[greenPinsE[i]] &= ~PORT_PCR_MUX_MASK;
    PORTE->PCR[greenPinsE[i]] |= PORT_PCR_MUX(1);
  }
  
  PORTE->PCR[redPin] &= ~PORT_PCR_MUX_MASK;
  PORTE->PCR[redPin] |= PORT_PCR_MUX(1);
	PORTE->PCR[redPin] |= PORT_PCR_DSE_MASK;
  
  // Set Data Direction Registers for PortB and PortE
  PTB->PDDR |= (MASK(8) | MASK(9) | MASK(10) | MASK(11));
  PTE->PDDR |= (MASK(2) | MASK(3) | MASK(4) | MASK(5) | MASK(11) | MASK(21));
}

void offGreenLed() {
  for (uint8_t i = 0; i < 4; i++) {
		PTB->PCOR |= MASK(greenPinsB[i]);
		PTE->PCOR |= MASK(greenPinsE[i]);
  }
}

void offRedLed() {
	PTE->PCOR |= MASK(redPin);
}

void offAllLed() {
  offGreenLed();
  offRedLed();
}


void toggleOnOffLed(GPIO_Type *gpio, uint8_t pin) {
	gpio->PSOR |= MASK(pin);
  osDelay(100);
  gpio->PCOR |= MASK(pin);
}

void runningGreenLed() {
  offGreenLed();
  
	for (uint8_t i = 0; i < 4; i++) {
		if (!isMove) {
			break;
		}
    toggleOnOffLed(PTB, greenPinsB[i]);
  }
  
  for (uint8_t i = 0; i < 4; i++) {
		if (!isMove) {
			break;
		}
    toggleOnOffLed(PTE, greenPinsE[i]);
  }
}

void allGreenLedLit() {
  for (uint8_t i = 0; i < 4; i++) {
		if (isMove) {
			break;
		}
		PTB->PSOR |= MASK(greenPinsB[i]);
		PTE->PSOR |= MASK(greenPinsE[i]);
  }
}

void flashRedLed(uint16_t time) {
	PTE->PSOR |= MASK(redPin);
  osDelay(time);
  PTE->PCOR |= MASK(redPin);
  osDelay(time);
}
