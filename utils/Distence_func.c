#include "Math.h"
#include "../utils/STD_TYPES.h"
#include "../HAL/gps.h"

# define M_PI           3.14159265358979323846
#define POISON_LATITUDE   3003.84363  // Replace with the latitude of the poison
#define POISON_LONGITUDE  3116.74459 // Replace with the longitude of the poison
#define TOLERANCE         5.0      // Tolerance in meters
// use valid final postion numbers for the 2 pervious constents


f64_t to_radians(f64_t degree)
{
    f64_t one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

f64_t calc_distance(f64_t lat1, f64_t long1,
                     f64_t lat2, f64_t long2)
{
		f64_t dlong;
		f64_t dlat;
		f64_t ans;
    lat1 = to_radians(lat1);
    long1 = to_radians(long1);
    lat2 = to_radians(lat2);
    long2 = to_radians(long2);

    dlong = long2 - long1;
    dlat = lat2 - lat1;

    ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);

    return 2 * asin(sqrt(ans)) * 6371 * 1000;
}


int is_poison_reached(f64_t current_latitude, f64_t current_longitude) {
    // Calculate the distance between the current location and the poison location
    f64_t distance = calc_distance(current_latitude, current_longitude,
                                    POISON_LATITUDE, POISON_LONGITUDE);

    // Check if the distance is within the tolerance
    if (distance <= TOLERANCE) {
        return 1; // Poison is reached
    } else {
        return 0; // Poison is not reached
    }
}


void Fdelay_ms(int n)
{ // delay for n milliseconds
	int i;
	int j;
	for(i = 0; i < n; i++){
		for(j = 0; j < 3180;j++){

		}
	}
}

//f64_t total_distance_covered(f64_t start_latitude, f64_t start_longitude){
//    f64_t current_latitude, current_longitude;
//    f64_t distance_covered = 0.0;
//	f64_t d =0.0;
//
//    // Get the current geographic point
//
//
//		geographic_point point = get_geographic_point();
//    current_latitude = point.latitude;
//    current_longitude = point.longtude;
//
//
//    // Calculate the distance between the start point and the current point
//    distance_covered = calc_distance(start_latitude, start_longitude,
//                                      current_latitude, current_longitude);
//
//    while (!is_poison_reached(current_latitude, current_longitude)) {
//        // Wait for some time before refreshing the geographic point
//        Fdelay_ms(1000);
//
//        // Get the updated geographic point
//
//
//
//				point = get_geographic_point();
//        current_latitude = point.latitude;
//        current_longitude = point.longtude;
//
//        // Calculate the distance between the previous point and the updated point
//         d = calc_distance(start_latitude, start_longitude,
//                                  current_latitude, current_longitude);
//
//        // Add the distance covered in the current step to the total distance covered so far
//        distance_covered += d;
//    }
//
//    return distance_covered;}





