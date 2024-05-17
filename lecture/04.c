#include <stdio.h>
#include "is_leap_year.h"

unsigned char days_in_month(unsigned char m, unsigned short y) {
    switch (m) {
        case 9:
        case 4:
        case 6:
        case 11: 
            return 30;
        case 2:
            if (is_leap_year(y)) {
                return 29;
            }
            return 28;
        default:
            return 31;
    }
}