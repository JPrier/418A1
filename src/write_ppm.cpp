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
  // open file
  std::ofstream file;
  file.open(filename.c_str(), std::ios::out | std::ios::binary);
  // write P3
  file << "P" << 3 << "\n";
  // write width space height
  file << width << " " << height << "\n";
  // write 255
  file << 255 << "\n";
  // write all data space r space g space b space all casted as int
  for (int i = 0;  i < width*height; i++) {
    for (int nc = 0; nc < num_channels; nc++) {
      file << " " << (int)data[i+nc];
    }
    file << " "; 
  }
  file.close;
  return true;
}
