
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include <HAL/LCD.h>
#include "MCAL/UART.h"
#include "string.h"
#include "stdlib.h"
#include "HAL/gps.h"
#include "HAL/GPIO.h"
#include "utils/Distence_func.h"
#include "HAL/LCD.h"
#include "MCAL/timer.h"

int main(){
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_INT | SYSCTL_MAIN_OSC_DIS);

    PortB_Init();
    PORTF_init();
    SysTick_Init();
    UART5_initialization();

    lcd_init();
    lcd_cmd(lcd_Clear);
    lcd_cmd(lcd_Home);
    lcd_str("Waiting");
    lcd_cmd(second_row);
    lcd_str("for GPS data ..");
    delay_ms(500);

    GPIO_PORTF_DATA_R = 0x02;
    //GPIO_setLedValue(1, 1);
    while(1){
        geographic_point p = get_geographic_point();

        if(p.Valid) {

            if(is_poison_reached(p.latitude, p.longtude)) {
                  lcd_cmd(lcd_Clear);
                  lcd_cmd(lcd_Home);
                  GPIO_PORTF_DATA_R=0X08;
                  lcd_str("We reached");
                  lcd_cmd(second_row);
                  lcd_str("our point :O");
                  delay_ms(1000);
              }else{
                  GPIO_PORTF_DATA_R=0X02 ;
                  lcd_cmd(lcd_Clear);
                  lcd_cmd(lcd_Home);
                  lcd_str("Checking again");
                  delay_ms(1000);
              }


            lcd_cmd(lcd_Clear);
            lcd_cmd(lcd_Home);
            lcd_str("The Lat is:");
            lcd_cmd(second_row);
            lcd_str(p.lat_str);
            delay_ms(1000);
            lcd_cmd(lcd_Clear);
            lcd_cmd(lcd_Home);
            lcd_str("The Long is:");
            lcd_cmd(second_row);
            lcd_str(p.lon_str);
            delay_ms(1000);

        }
    }
}

