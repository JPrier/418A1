#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      if (y % 2 == 0) {
        if (x % 2 == 0) {
          bayer[x+width*y] = rgb[1+3*(x+width*y)];
        } else {
          bayer[x+width*y] = rgb[2+3*(x+width*y)];
        }
      } else {
        if (x % 2 == 0) {
          bayer[x+width*y] = rgb[3*(x+width*y)];
        } else {
          bayer[x+width*y] = rgb[1+3*(X+width*y)];
        }
      }
    }
  }
}
