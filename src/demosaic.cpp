#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  int curr_index = 0;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      int ramt = 0;
      int gamt = 0;
      int bamt = 0;
      int ravg = 0;
      int gavg = 0;
      int bavg = 0;
      //calc every index
      curr_index = x+width*y;
      int tl = curr_index - width - 1;
      int t = curr_index - width;
      int tr = curr_index - width + 1;
      int l = curr_index - 1;
      int r = curr_index + 1;
      int bl = curr_index + width - 1;
      int b = curr_index + width;
      int br = curr_index + width + 1;
      if (y%2 == 0) {
	if (x%2 == 0) {
	  //green
	  if (y != 0) {
	    //not top
	    ramt += 1;
	    ravg += bayer[t];
	  }
	  if (y!=height) {
	    //not bottom
	    ramt += 1;
	    ravg += bayer[b];
	  }
	  if (x != 0) {
	    //not left
	    bamt += 1;
	    bavg += bayer[l];
	  }
	  if (x != width) {
	    //not right
	    bamt += 1;
	    bavg += bayer[r];
	  }
	  if (ramt != 0) {
            ravg = ravg/ramt;
          } else {ravg = 0;}
          if (bamt != 0) {
            bavg = bavg/bamt;
          }
          rgb[2+3*curr_index] = bavg;
          rgb[3*curr_index] = ravg;
	  rgb[1+3*curr_index] = bayer[curr_index];
	} else {
	  //blue
	  if (y!=0) {
	    if (x!=0) {
	      ramt += 1;
	      ravg += bayer[tl];
	    } 
	    if (x != width-1) {
	      ramt += 1;
	      ravg += bayer[tr];
	    }
	    gamt += 1;
	    gavg += bayer[t];
	  }
	  if (y!=height-1){
	    if (x!=0) {
	      ramt += 1;
	      ravg += bayer[bl];
	    }
	    if (x != width) {
	      ramt += 1;
	      ravg += bayer[br];
	    }
	    gamt += 1;
	    gavg += bayer[b];
	  }
	  if (x!=0) {
	    gamt += 1;
	    gavg += bayer[l];
	  }
	  if (x!=width) {
	    gamt += 1;
	    gavg += bayer[r];
	  }
	}
	if (ramt != 0) {
            ravg = ravg/ramt;
        } else {ravg = 0;}
        if (gamt != 0) {
            gavg = gavg/gamt;
        } else {gavg = 0;}
        rgb[3*curr_index] = ravg;
        rgb[1+3*curr_index] = gavg;
        rgb[2+3*curr_index] = bayer[curr_index];
      } else {
	if (x%2 == 0) {
	  //red
	  if (y!=0) {
	    if (x!=0) {
	      bamt += 1;
	      bavg += bayer[tl];
	    }
	    if (x != width) {
	      bamt += 1;
	      bavg += bayer[tr];
	    }
	    gamt += 1;
	    gavg += bayer[t];
	  }
	  if (y!=height) {
	    if (x!=0) {
	      bamt += 1;
	      bavg += bayer[bl];
	    }
	    if (x!=width) {
	      bamt += 1;
	      bavg += bayer[br];
	    }
	    gamt += 1;
	    gavg += bayer[b];
	  }
	  if (x!=0) {
	    gamt += 1;
	    gavg += bayer[l];
	  }
	  if (x!=width) {
	    gamt += 1;
	    gavg += bayer[r];
	  }
	  if (gamt != 0) {
            gavg = gavg/gamt;
          } else {gavg = 0;}
          if (bamt != 0) {
            bavg = bavg/bamt;
          } else {bavg = 0;}
	  rgb[3*curr_index] = bayer[curr_index];
          rgb[1+3*curr_index] = gavg;
          rgb[2+3*curr_index] = bavg;
	} else {
            //green
            if (y!=0) {
              bamt += 1;
	      bavg += bayer[t];
            }
            if (y!=height) {
	      bamt += 1;
	      bavg += bayer[b];
	    }
            if (x!=0) {
	      ramt += 1;
	      ravg += bayer[l];
	    }
            if (x!=width) {
	      ramt += 1;
	      ravg += bayer[r];
	    }
	    if (ramt != 0) {
                ravg = ravg/ramt;
            } else {ravg = 0;}
            if (bamt != 0) {
                bavg = bavg/bamt;
            } else {bavg = 0;}
            rgb[3*curr_index] = ravg;
            rgb[1+3*curr_index] = bayer[curr_index];
            rgb[2+3*curr_index] = bavg;
	}
      }
      //curr_index++;
    }
  }
}
