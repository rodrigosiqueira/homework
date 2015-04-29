#include <stdio.h>
#include <string.h>
#include "agg_pixfmt_rgb.h"

enum
{
  frameWidth = 320,
  frameHeight = 200
};

int writePPM (const unsigned char * buf, 
              unsigned width,
              unsigned height,
              const char * path)
{
  FILE * file = fopen(path, "wb");
  if (file)
  {
    fprintf(file, "P6 %d %d 255 ", frameWidth, frameHeight);
    fwrite(buf, 1, frameWidth * frameHeight * 3, file);
    fclose(file);
    return true;
  }
  return false;
}

//Drawn a black frame around the rendering buffer
template<class Ren>
void drawBlackFrame(Ren& ren)
{
  unsigned i;
  agg::rgba8 c(0, 0, 0);

  for (i = 0; i < ren.height(); ++i)
  {
    ren.copy_pixel(0, i, c);
    ren.copy_pixel(ren.width() - 1, i, c);
  }
/*
  for (i = 0; i < ren.width(); ++i)
  {
    ren.copy_pixel(i, 0, c);
    ren.copy_pixel(i, ren.height() -1, c);
  }
*/
}

int main(int argc, char ** argv)
{
  //Allocate the buffer
  unsigned char * buffer = new unsigned char[frameWidth * frameHeight * 3];

  //Clear buffer "manually"
  memset(buffer, 255, frameWidth * frameHeight * 3);

  //Create the rendering buffer object
  agg::rendering_buffer rbuf(buffer, frameWidth, frameHeight, frameWidth * 3);

  //Create the pixel format renderer
  agg::pixfmt_rgb24 pixf(rbuf);

  //Draw a diagonal line
  unsigned i;
  for(i = 0; i < pixf.height() / 2; ++i)
    pixf.copy_pixel(i, i, agg::rgba8(127, 200, 98));

  drawBlackFrame(pixf);
  writePPM(buffer, frameWidth, frameHeight, "agg_test.ppm");

  delete [] buffer;
  return 0;
}
