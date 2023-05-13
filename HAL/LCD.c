#include <HAL/LCD.h>
#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "MCAL/timer.h"


void lcd_init(void){
    lcd_cmd(Set5x7FontSize);
    lcd_cmd(four_bit_mode);
    lcd_cmd(lcd_EntryMode);
    lcd_cmd(lcd_Clear);
    lcd_cmd(lcd_DisplayOn);
}

void lcd_cmd(unsigned char cmd){
    lcd_write(cmd & 0xF0, 0);
    lcd_write(cmd<<4, 0);
    if(cmd < 4){
        delay_ms(2);
    }
    else{
        delay_us(40);
    }
}

void lcd_write(unsigned char c, unsigned char ctrl){
    c &= 0XF0;
    ctrl &= 0x0F;
    GPIO_PORTB_DATA_R = c | ctrl;
    GPIO_PORTB_DATA_R = c | ctrl | EN;
    delay_us(1);
    GPIO_PORTB_DATA_R = c;
    GPIO_PORTB_DATA_R = 0;
}

void lcd_char(unsigned char data, unsigned char ctrl){
    lcd_write(data&0xF0, RS);
    lcd_write(data<<4, RS);
    delay_us(40);
}

void lcd_str( char *str){
    int i;
    for( i = 0; *str!=0; i++){
        lcd_char(*(str++),RS);
    }
}



