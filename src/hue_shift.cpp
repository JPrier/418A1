#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  for (int i = 0; i< width*height; i++) {
    double h;
    double s;
    double v;
    double r;
    double g;
    double b;
    rgb_to_hsv(rgb[3*i], rgb[1+3*i], rgb[2+3*i], h, s, v);
    h += shift;
    if (h > 360) {h-=360;}
    if (h < 0) {h+=360;}
    hsv_to_rgb(h, s, v, r, g, b);
    shifted[3*i] = r;
    shifted[1+3*i] = g;
    shifted[2+3*i] = b;
  }
}
