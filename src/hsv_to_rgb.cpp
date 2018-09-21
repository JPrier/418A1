#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{

  double c = v * s;
  double hp = h/60;
  double x = c * (1 - std::fabs(std::fmod(hp, 2)-1));
  r = 0;
  g = 0;
  b = 0;

  if (0 <= hp && hp <= 1) {
    r = c;
    g = x;
  } else if (1 <= hp && hp <= 2) {
    r = x;
    g = c;
  } else if (2 <= hp && hp <= 3) {
    g = c;
    b = x;
  } else if (3 <= hp && hp <= 4) {
    g = x;
    b = c;
  } else if (4 <= hp && hp <= 5) {
    r = x;
    b = c;
  } else if (5 <= hp && hp <= 6) {
    r = c;
    b = x;
  }
  
  double m = v - c;
  r += m;
  g += m;
  b += m;
}
