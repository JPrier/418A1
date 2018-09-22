#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  int a_src;
  int a_dst;
  int a_both;
  for (int i = 0; i < width*height; i++) {
      
    double alpha = A[3+4*i]/255.0;
    C[4*i] = alpha*A[4*i] + (1-alpha)*B[4*i];
    C[1+4*i] = alpha*A[1+4*i] + (1-alpha)*B[1+4*i];
    C[2+4*i] = alpha*A[2+4*i] + (1-alpha)*B[2+4*i];
  }
}
