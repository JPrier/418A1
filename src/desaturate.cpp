#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  for (int i = 0; i < width*height; i++) {
    double h;
    double s;
    double v;
    double r;
    double g;
    double b;
    rgb_to_hsv(rgb[3*i], rgb[1+3*i], rgb[2+3*i], h, s, v);
    s*=factor;
    hsv_to_rgb(h,s,v,r,g,b);
    desaturated[3*i] = r;
    desaturated[1+3*i] = g;
    desaturated[1+3*i] = b;
  }
}
