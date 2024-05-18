#include "motor.h"

void initPWM(void) {
  // power on the port
  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK;
    
  PORTA->PCR[PTA4_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTA->PCR[PTA4_Pin] |= PORT_PCR_MUX(3);
  
  PORTA->PCR[PTA5_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTA->PCR[PTA5_Pin] |= PORT_PCR_MUX(3);
  
  PORTC->PCR[PTC2_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTC->PCR[PTC2_Pin] |= PORT_PCR_MUX(4);
  
  PORTC->PCR[PTC3_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTC->PCR[PTC3_Pin] |= PORT_PCR_MUX(4);
  
  PORTA->PCR[PTA12_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTA->PCR[PTA12_Pin] |= PORT_PCR_MUX(3);
  
  PORTA->PCR[PTA13_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTA->PCR[PTA13_Pin] |= PORT_PCR_MUX(3);
  
  PORTB->PCR[PTB0_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTB->PCR[PTB0_Pin] |= PORT_PCR_MUX(3);
  
  PORTB->PCR[PTB1_Pin] &= ~PORT_PCR_MUX_MASK;
  PORTB->PCR[PTB1_Pin] |= PORT_PCR_MUX(3);
  
  // enable clock (TPM0, TPM1)
  SIM->SCGC6 |= (SIM_SCGC6_TPM0_MASK | SIM_SCGC6_TPM1_MASK);
  
  // select clock source
  SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
  SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
  
  // 50Hz, 0% duty cycle
  TPM0->MOD = PWM_MOD;
  TPM0_C1V = 0;
  TPM0_C2V = 0;
  
  TPM1->MOD = PWM_MOD;
  TPM1_C0V = 0;
  TPM1_C1V = 0;
  
  // configure the clock : mode of operation, prescaler (p.552)
  TPM0->SC &= ~(TPM_SC_CMOD_MASK | TPM_SC_PS_MASK);
  TPM0->SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(7));
  TPM0->SC &= ~TPM_SC_CPWMS_MASK;
  
  TPM1->SC &= ~(TPM_SC_CMOD_MASK | TPM_SC_PS_MASK);
  TPM1->SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(7));
  TPM1->SC &= ~TPM_SC_CPWMS_MASK;
  
  // start PWM
  TPM0_C1SC &= ~(TPM_CnSC_ELSA_MASK | TPM_CnSC_ELSB_MASK | TPM_CnSC_MSA_MASK | TPM_CnSC_MSB_MASK);
  TPM0_C1SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));  // L2
  TPM0_C2SC &= ~(TPM_CnSC_ELSA_MASK | TPM_CnSC_ELSB_MASK | TPM_CnSC_MSA_MASK | TPM_CnSC_MSB_MASK);
  TPM0_C2SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));  // L2
  
	TPM1_C0SC &= ~(TPM_CnSC_ELSA_MASK | TPM_CnSC_ELSB_MASK | TPM_CnSC_MSA_MASK | TPM_CnSC_MSB_MASK);
  TPM1_C0SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));  // R2
  TPM1_C1SC &= ~(TPM_CnSC_ELSA_MASK | TPM_CnSC_ELSB_MASK | TPM_CnSC_MSA_MASK | TPM_CnSC_MSB_MASK);
  TPM1_C1SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));  // R2
}

int dutyCycleCnV(int dutyCycle) {
	return ((PWM_MOD * dutyCycle)/100);
}

/* motor control */
void motorControl(int maxSpeed, int dir) {	
	if (maxSpeed == 0) {
		TPM0_C1V = 0;
		TPM0_C2V = 0;
		TPM1_C0V = 0;
		TPM1_C1V = 0;
	}
	else if (dir == FW) {
		TPM0_C1V = dutyCycleCnV(100);
		TPM0_C2V = 0;
		TPM1_C0V = dutyCycleCnV(100);
		TPM1_C1V = 0;
	}
	else if (dir == BW) {
		TPM0_C1V = 0;
		TPM0_C2V = dutyCycleCnV(100);
		TPM1_C0V = 0;
		TPM1_C1V = dutyCycleCnV(100);
	}
	else if (dir == LEFT) {
		TPM0_C1V = 0;
		TPM0_C2V = dutyCycleCnV(90);
		TPM1_C0V = dutyCycleCnV(90);
		TPM1_C1V = 0;
	}
	else if (dir == RIGHT) {
		TPM0_C1V = dutyCycleCnV(90);
		TPM0_C2V = 0;
		TPM1_C0V = 0;
		TPM1_C1V = dutyCycleCnV(90);
	}
	else {
		TPM0_C1V = 0;
		TPM0_C2V = 0;
		TPM1_C0V = 0;
		TPM1_C1V = 0;
	}
}
