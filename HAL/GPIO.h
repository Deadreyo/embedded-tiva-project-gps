#ifndef GPIO_H
#define GPIO_H

void PORTF_init();
void GPIO_setLedValue (unsigned char ledColor, unsigned char ledState);
void Operation_LED (float distence);
unsigned char GPIO_getSwitchesValue (unsigned char sw);

#endif
