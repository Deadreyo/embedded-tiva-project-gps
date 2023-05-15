#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "timer.h"

void SysTick_Init(void){
    NVIC_ST_CTRL_R = 0;                 // Disable systick timer
    NVIC_ST_RELOAD_R = 0xFFFFFF;
    NVIC_ST_CURRENT_R = 0;              // Clear the counter
    NVIC_ST_CTRL_R = 5;                 // Enable the counter and system CLK
}


void delay_ms(long long ms) {
    while(ms--){
        NVIC_ST_CTRL_R = 0x05;

        NVIC_ST_RELOAD_R = 16e6 / 1000;

        while( (NVIC_ST_CTRL_R & 0x10000) == 0);
    }
}


void delay_us(long long us){
    while(us--){
        NVIC_ST_CTRL_R = 0x05;

        NVIC_ST_RELOAD_R = 16e6 / 1000 / 1000;

        while( (NVIC_ST_CTRL_R & 0x10000) == 0);
    }
}
