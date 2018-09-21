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
  	for (int x = 0; x < width; x++) {
    		int index =  x + (height*y-1);
      	for (int n = 0; n < num_channels; n++) {
  			     rotated[n+num_channels*index] = input[n+num_channels*(y+width*x)];
  		}
  	}
  }
}
