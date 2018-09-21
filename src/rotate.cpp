#include "rotate.h"


void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  int i = 0;
  rotated.resize(height*width*num_channels);
  for(int x = width; x > 0; x--) {
    for (int y = 0; y < height; y++) {
      int index =  x-1+y*width;//y + (width*x-1);
      for (int n = 0; n < num_channels; n++) {
	rotated[n+num_channels*i] = input[n+num_channels*index];
      }
      i++;
    }
  }
}
