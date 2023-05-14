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

void get_RMC_string(void);

geographic_point get_geographic_point(void);


#endif
