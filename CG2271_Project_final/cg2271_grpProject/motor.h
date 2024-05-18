#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"

#define PTA4_Pin     4                // (TPM0_CH1)
#define PTA5_Pin     5                // (TPM0_CH2)
#define PTC2_Pin     2                // (TPM0_CH1)
#define PTC3_Pin     3                // (TPM0_CH2)
#define PTA13_Pin   13            		// (TPM1_CH0)
#define PTA12_Pin   12            		// (TPM1_CH1)
#define PTB0_Pin     0              	// (TPM1_CH0)
#define PTB1_Pin     1             		// (TPM1_CH1)

#define PWM_MOD			35				

#define FW             1
#define BW             2
#define RIGHT     		 3
#define LEFT				   4

void initPWM(void);
int dutyCycleCnV(int dutyCycle);
void motorControl(int maxSpeed, int angle);
