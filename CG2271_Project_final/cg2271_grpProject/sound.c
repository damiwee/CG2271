#include "sound.h"

uint8_t coffinDurations[] = {
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  10,10,10,10,
  };

uint32_t coffinMelody[] = {
  N_AS4, N_AS4, N_AS4, N_AS4,
  N_AS4, N_AS4, N_AS4, N_AS4,
  N_D5, N_D5, N_D5, N_D5,
  N_C5, N_C5, N_C5, N_C5, 
  N_F5, N_F5, N_F5, N_F5, 
  N_G5, N_G5, N_G5, N_G5,
  N_G5, N_G5, N_G5, N_G5, 
  N_G5, N_G5, N_G5, N_G5, 
  N_C5, N_AS4, N_A4, N_F4,
  N_G4, REST, N_G4, N_D5,
  N_C5, REST, N_AS4, REST,
  N_A4, REST, N_A4, N_A4,
  N_C5, REST, N_AS4, N_A4, 
  N_G4, REST, N_G4, N_AS5,
  N_A5, N_AS5, N_A5, N_AS5,
  N_G4, REST, N_G4, N_AS5,
  N_A5, N_AS5, N_A5, N_AS5,
  N_G4, REST, N_G4, N_D5,
  N_C5, REST, N_AS4, REST,
  N_A4, REST, N_A4, N_A4,
  N_C5, REST, N_AS4, N_A4, 
  N_G4, REST, N_G4, N_AS5,
  N_A5, N_AS5, N_A5, N_AS5,
  N_G4, REST, N_G4, N_AS5,
  N_A5, N_AS5, N_A5, N_AS5
 };

 int pirateMelody[] = {
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
  
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
  NOTE_C5, NOTE_A4, NOTE_B4, REST,
  
  NOTE_A4, NOTE_A4,
  //Repeat of first part
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
  NOTE_A4, NOTE_G4, NOTE_A4, REST,
  
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
  NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
  
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
  NOTE_D5, NOTE_E5, NOTE_A4, REST,
  NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
  NOTE_C5, NOTE_A4, NOTE_B4, REST,
  //End of Repeat
  
  NOTE_E5, REST, REST, NOTE_F5, REST, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
  NOTE_D5, REST, REST, NOTE_C5, REST, REST,
  NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,
  
  NOTE_E5, REST, REST, NOTE_F5, REST, REST,
  NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
  NOTE_D5, REST, REST, NOTE_C5, REST, REST,
  NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4
};

int pirateMelodyDurations[] = {
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  4, 8, 4, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 4,
  
  4, 8,
  //Repeat of First Part
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 8, 8,
  8, 8, 8, 4, 8,
  
  8, 8, 4, 8, 8,
  4, 8, 4, 8,
  8, 8, 4, 8, 8,
  8, 8, 4, 4,
  //End of Repeat
  
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8, 4,
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 2,
  
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8, 4,
  4, 8, 4, 4, 8, 4,
  8, 8, 8, 8, 8, 2
};

void initSoundPWM(){
	// Enable Clock Gating for Port E
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	
	// Configure Mode 3 for PWM pin operation
	PORTE->PCR[PTE22_Pin] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[PTE22_Pin] |= PORT_PCR_MUX(3);
	
	// Enable CLock GAting for Timer1
	SIM->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	
	// Select Clock for TPM module
	SIM->SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);
	
	// Set Module Value 48000000 / 128 = 375000 / 7500 = 50Hz
	TPM2->MOD = 7500;
	
	// Update SnC register: CMOD = 01, PS = 111 (128)
	TPM2->SC &= ~((TPM_SC_CMOD_MASK) | (TPM_SC_PS_MASK));
	TPM2->SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(7));
	TPM2->SC &= ~TPM_SC_CPWMS_MASK;
	
	// Enable PWM on TPM2 Channel 0 ->PTE22
	TPM2_C0SC &= ~((TPM_CnSC_ELSB_MASK) |(TPM_CnSC_ELSA_MASK) | (TPM_CnSC_MSB_MASK) | (TPM_CnSC_MSA_MASK));
	TPM2_C0SC |= (TPM_CnSC_ELSB(1) | TPM_CnSC_MSB(1));
}

void playCoffin(void) {
	int size = sizeof(coffinMelody) / sizeof(int);
	for (int i = 0; i < size; i++) {
		if(!(isEnd == 1)) {
			break;
		}
		
		uint8_t noteDuration = TEMPO / coffinDurations[i];
		osDelay(250);
		
		// Set PWM frequency for the current note
		uint32_t tone = coffinMelody[i];
		TPM2_C0V = FREQ_2_MOD(tone) / 4; // 25% duty cycle
		TPM2->MOD = FREQ_2_MOD(tone);
		
		osDelay(noteDuration * 1.45);
	}
}
void playPirates(void) {
	int size = sizeof(pirateMelody) / sizeof(int);
	for (int i = 0; i < size; i++) {
		if(isEnd) {
			break;
		}
		uint8_t noteDuration = TEMPO / pirateMelodyDurations[i];
		osDelay(250);
		// Set PWM frequency for the current note
		uint32_t tone = pirateMelody[i];
		TPM2_C0V =FREQ_2_MOD(tone) / 4; // 25% duty cycle
		TPM2->MOD = FREQ_2_MOD(tone);
		
		// Play the current note
		osDelay(noteDuration);
	}
}

void offAudio(void) {
	TPM2_C0V = 0;
}
