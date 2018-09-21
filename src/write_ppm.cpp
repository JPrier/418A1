#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  std::ofstream file;
  file.open(filename.c_str(), std::ios::out | std::ios::binary);
  if (!file) { return false; }
  file << "P" << 3 << "\n";
  file << width << " " << height << "\n";
  file << 255 << "\n";
  if (num_channels == 3) {
    for (int i = 0;  i < width*height; i++) {
      file << " " << (int)data[i*3] << " " << (int)data[i*3+1] << " " << (int)data[i*3+2] << " "; 
    }
  } else if (num_channels == 1) {
    for (int i = 0;  i < width*height; i++) {
      file << " " << (int)data[i] << " " << (int)data[i] << " " << (int)data[i] << " "; 
    }
  }
  file.close();
  return true;
}
