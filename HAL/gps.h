#ifndef GPS_H
#define GPS_H

typedef struct
{
	  _Bool Valid;
    double latitude;
    double longtude;
    char lat_str[30] ;
    char lon_str[30] ;
} geographic_point;

void UART5_initialization();
//void gps_init(void);

geographic_point get_geographic_point(void);

void get_RMC_string(void);

//double parse(char *degree_str);
char UART5_READ_BYTE();

#endif
