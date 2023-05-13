#include"helpers.h"
#include<stdbool.h>
float str_to_float(const char *str) {
    float result = 0.0;
    int sign = 1;
    bool decimal_point = false;
    float decimal_factor = 0.1;

    if (*str == '-') {
        sign = -1;
        str++;
    }

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            if (decimal_point) {
                result += (*str - '0') * decimal_factor;
                decimal_factor /= 10.0;
            } else {
                result = result * 10 + (*str - '0');
            }
        } else if (*str == '.') {
            decimal_point = true;
        } else {
            break;
        }
        str++;
    }

    return sign * result;
}
