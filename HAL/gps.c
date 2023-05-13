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


geographic_point get_geographic_point()
{
//		char lat[30] = "";
//    char lon[30] = "";
	char lat_dir[] = "";
	char lon_dir[] = "";
    char valid[] = "";
		geographic_point p;
		char *token ;

		get_RMC_string();

		token = strtok(RMC_STRING, ",");
		token= strtok (NULL,",");
				strcpy(valid,token);
		if (strcmp(valid, "A")==0)
		{
			p.Valid = 1;

		token= strtok (NULL,",");
				strcpy(p.lat_str,token);

		token= strtok (NULL,",");
				strcpy(lat_dir,token);
			
		token= strtok (NULL,",");
				strcpy(p.lon_str,token);

		token= strtok (NULL,",");
				strcpy(lon_dir,token);



		if (lat_dir[0] == 'N')
			p.latitude = str_to_float (p.lat_str);
		else
			p.latitude = -str_to_float (p.lat_str);

		if (lon_dir[0] == 'E')
			p.longtude = str_to_float (p.lon_str);
		else
			p.longtude =-str_to_float (p.lon_str);
		}
		
		else
			p.Valid = 0;
		
    return p;
}


