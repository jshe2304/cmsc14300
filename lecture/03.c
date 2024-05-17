#include <stdio.h>
#include <math.h>

int is_leap_year(unsigned short y) {
  if (y % 400 == 0) {
    return 1;
  } else if (y % 100 == 0) {
    return 0;
  } else if (y % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int is_leap_year(unsigned short y) {
  return (y % 400 || (y % 4 && !(y % 100)))
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;

    return sqrt(dx * dx, dy * dy);
}