#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  for(int y = 0; y < height; y++) {
    for(int x = 0; x < width; x++) {
      for(int i = 0; i < num_channels; i++){
        rotated[i + num_channels*(x+width*y)] = input[i + num_channels*(y+width*x)];
      }
    }
  }
}
