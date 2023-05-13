#include "Math.h"
#include "..\utils\STD_TYPES.h"
#define M_PI           3.14159265358979323846
#define POISON_LATITUDE   37.7749  // Replace with the latitude of the poison
#define POISON_LONGITUDE  -122.4194 // Replace with the longitude of the poison
#define TOLERANCE         1.0      // Tolerance in meters

f64_t to_radians(f64_t degree);
f64_t calc_distance(f64_t lat1, f64_t long1,f64_t lat2, f64_t long2);
int is_poison_reached(f64_t current_latitude, f64_t current_longitude);
void Fdelay_ms(int n);
f64_t total_distance_covered(f64_t start_latitude, f64_t start_longitude);
