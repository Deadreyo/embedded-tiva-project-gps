#include "GPIO.h"
#include "../utils/bit_utils.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "../utils/STD_TYPES.h"


void PORTF_init(void){

			
			SYSCTL_RCGCGPIO_R |= 0x00000020;
			while(((SYSCTL_PRGPIO_R)& 0x00000020) == 0){};	
			GPIO_PORTF_LOCK_R = 0x4CF434B;
			GPIO_PORTF_CR_R |= 0X1F;
			GPIO_PORTF_AMSEL_R &= 0x00;
			GPIO_PORTF_DEN_R |= 0x1F;
			GPIO_PORTF_DIR_R |= 0x0E;
			GPIO_PORTF_AFSEL_R &= 0x00;
			GPIO_PORTF_PCTL_R &=0x00000000;
			GPIO_PORTF_PUR_R |= 0X11;				
}			

			
			
void GPIO_setLedValue (unsigned char ledColor, unsigned char ledState) { // two parameters one to select led second to on/off 51 ?


	switch (ledColor) {

case RED_LED: switch (ledState){
	case LED_OFF: CLR_BIT (GPIO_PORTF_DATA_R, 1); break;
	case LED_ON:  SET_BIT (GPIO_PORTF_DATA_R,1); break;
	default: break;
}
break;

case BLUE_LED: switch (ledState){
	case LED_OFF: CLR_BIT (GPIO_PORTF_DATA_R, 2); break; 
	case LED_ON: SET_BIT (GPIO_PORTF_DATA_R, 2); break;
	default: break;
} break;
case GREEN_LED: switch (ledState){
	case LED_OFF: CLR_BIT (GPIO_PORTF_DATA_R, 3); break; 
	case LED_ON: SET_BIT (GPIO_PORTF_DATA_R, 3); break;
default: break;
} 
break;
default: break;}
}

void Operation_LED (float distence){

if(distence <=1){
GPIO_setLedValue(GREEN_LED,LED_ON);
GPIO_setLedValue(BLUE_LED,LED_OFF);
GPIO_setLedValue(RED_LED,LED_OFF);
}
	else if (distence <=5 && distence >1){
GPIO_setLedValue(GREEN_LED,LED_OFF);
GPIO_setLedValue(BLUE_LED,LED_ON);
GPIO_setLedValue(RED_LED,LED_OFF);
	}
		
	else {
GPIO_setLedValue(GREEN_LED,LED_OFF);
GPIO_setLedValue(BLUE_LED,LED_OFF);
GPIO_setLedValue(RED_LED,LED_ON);}}
	
//
unsigned char GPIO_getSwitchesValue (unsigned char sw) { 
	switch (sw) {

case SW1 :return GET_BIT (GPIO_PORTF_DATA_R,4); break;
case SW2 :return GET_BIT (GPIO_PORTF_DATA_R,0); break;
default: return 0;}}
//


// Port B init
void PortB_Init(void){
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000002;     // Enable port F clock
  delay = SYSCTL_RCGC2_R;           // Reading register adds a delay
  GPIO_PORTB_LOCK_R = 0x4C4F434B;   // Unlock PortF PF0
  GPIO_PORTB_CR_R = 0xFF;           // Allow changes to PF4-0
  GPIO_PORTB_AMSEL_R = 0x00;        // Disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;   // GPIO clear bit PCTL
  GPIO_PORTB_DIR_R = 0xFF;          // PF4,PF0 input, PF3,PF2,PF1 output
  GPIO_PORTB_AFSEL_R = 0x00;        // No alternate function
  GPIO_PORTB_PUR_R = 0x00;          // Enable pullup resistors on PF4,PF0
  GPIO_PORTB_DEN_R = 0xFF;          // Enable digital pins PF4-PF0
}
