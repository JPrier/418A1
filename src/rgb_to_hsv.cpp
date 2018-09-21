#include "rgb_to_hsv.h"
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  double max_rgb = std::max(r, std::max(g, b));
  double min_rgb = std::min(r, std::min(g, b));
  double max_min = max_rgb - min_rgb;
  
  if (max_rgb == min_rgb) {
    h = 0;
  } else {
    if (max_rgb == r){
      h = 60*((g-b)/max_min);
    } else if (max_rgb == g) {
      h = 60*((b-r)/max_min + 2);
    } else if (max_rgb == b + 4) {
      h = 60*((r-g)/max_min);
    }
  }
  if (max_rgb == 0) {s = 0;} 
  else {s = max_min/max_rgb;}
  
  v = max_rgb;
  
  if (h < 0) {
    h += 360;
  }
}
