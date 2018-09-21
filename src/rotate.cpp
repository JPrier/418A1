#include "rotate.h"


void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  int intarray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int inp[9];
  rotated.resize(height*width*num_channels);
  for(int y = 0; y < 3; y++) {
  	for (int x = 0; x < 3; x++) {
    		int index =  x + (3*y-1);
      	for (int n = 0; n < 1; n++) {
  			     inp[n+1*index] = intarray[n+1*(y+3*x)];
  		}
  	}
  }
}
