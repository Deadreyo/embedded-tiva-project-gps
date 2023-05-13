#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "timer.h"

void SysTick_Init(void){
    NVIC_ST_CTRL_R = 0;                 // Disable systick timer
    NVIC_ST_RELOAD_R = 12-1;        // Load 80 counts to reload register for 1 microsecond count
    NVIC_ST_CURRENT_R = 0;          // Clear the counter
    NVIC_ST_CTRL_R = 5;                 // Enable the counter and system CLK
}

void delay_ms(long long ms){
    long long i = ms * 1000;
    while(i--){
        delay_us(1);        // 1 us                             // loop for count milliseconds
    }
}

void delay_us(long long us){
    while(us--){
        while((NVIC_ST_CTRL_R&0x10000)==0){}        // Loop while count flag is down
    }
}
