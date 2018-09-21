#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  for(int i = 0; i < width*height; i++) {
    	int index = width - 1 - i + (i/width)*width*2;
	for (int n = 0; n < num_channels; n++) {
		reflected[num_channels*index+n] = input[num_channels*i+n];
	}
  }
}
