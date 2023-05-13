#include "gps.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "inc/tm4c123gh6pm.h"
#include "../MCAL/UART.h"
#include "../MCAL/timer.h"
#include"../utils/helpers.h"
 

	char RMC_LOG_NAME[] = "$GPRMC,";
	char RMC_STRING [80];

// recvives an RMS sentence form gps on URAT5
void get_RMC_string()
{
    char recievedChar;
    unsigned char i = 0; unsigned char Counter = 0;
	
    do
	{
		while(UART5_READ_BYTE() != RMC_LOG_NAME[i]);
		i++;
	}while(i <= 6);

    memset(RMC_STRING,0,80);
	do
	{
		recievedChar = UART5_READ_BYTE();
		RMC_STRING[Counter++] = recievedChar;
	}while(recievedChar != '*');
}

