#ifndef BIT_UTILS
#define BIT_UTILS
//*****************************************************************************
//
// set, clear, toggle, get 
//
//*****************************************************************************
#define SET_BIT(Var,BitNo) Var |= (1 << BitNo)         //set bit to 1
#define CLR_BIT(Var,BitNo) Var &= (~(1 << BitNo))      //set bit to 0
#define TOGGLE_BIT(Var,BitNo) Var ^= (1 << BitNo)

#define GET_BIT(Var,BitNo) Var & (1 << BitNo)          //returns 1 or 0 in bit location
#define GET_BIT_VALUE(Var,BitNo) (Var >> BitNo) & 1    //returns 1 or 0

#define CLR_BITS(Var,Bits) Var &= (~Bits)              //set bits to 0
#define SET_BITS(Var,Bits) Var |= Bits                 //set bits to 1

#define SET_H_BYTE(Var,BitNo,Value) Var |= (Value << (4*BitNo)) //set 4 bits to certain value used mostly in setting PCTL 


//*****************************************************************************
//
// pins
//
//*****************************************************************************
enum UARTS
{
	UART_0 ,
	UART_1 ,
	UART_2 ,
	UART_3 ,
	UART_4 ,
	UART_5 ,
    UART_6 , 
	UART_7
};

enum PORTS
{
	PORT_A ,
	PORT_B ,
	PORT_C ,
	PORT_D ,
	PORT_E ,
	PORT_F 
};

enum UART_GPIO
{
	UART0_GPIO ,
	UART1_GPIO ,
	UART3_GPIO ,
	UART4_GPIO = 2 ,
	UART2_GPIO  ,
	UART6_GPIO = 3 ,
    UART5_GPIO , 
	UART7_GPIO = 4
};

enum PORTA
{
	PA0 ,
	PA1 ,
	PA2 ,
	PA3 ,
	PA4 ,
	PA5 ,
	PA6 ,
	PA7 
};

enum PORTB
{
	PB0 ,
	PB1 ,
	PB2 ,
	PB3 ,
	PB4 ,
	PB5 ,
	PB6 ,
	PB7  
};

enum PORTC
{
	PC0 ,
	PC1 ,
	PC2 ,
	PC3 ,
	PC4 ,
	PC5 ,
	PC6 ,
	PC7  
};

enum PORTD
{
	PD0 ,
	PD1 ,
	PD2 ,
	PD3 ,
	PD4 ,
	PD5 ,
	PD6 ,
	PD7  
};

enum PORTE
{
	PE0 ,
	PE1 ,
	PE2 ,
	PE3 ,
	PE4  
};

enum PORTF
{
	SW2 ,
	RED_LED ,
	BLUE_LED ,
	GREEN_LED ,
	SW1 
};

enum LED
{
	RED = 0x2 ,
	BLUE = 0x4 ,
	GREEN = 0x8 ,
};

enum LED_CASE
{
LED_OFF,
LED_ON

}; 

enum SWITCHES_PDR
{
	PRESSED , 
	SW2_UNPRESSED = 0x01 ,
	SW1_UNPRESSED = 0x10 
    
};

#endif
