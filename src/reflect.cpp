#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      for(int i = 0; i < num_channels; i++){
        reflected[i + num_channels*((2*width - x) * y)] = input[i + num_channels*((x+width)*y)];
      }
    }
  }
}
