#include <stdio.h>
#include <stdlib.h>
#include "agg_rendering_buffer.h"

enum
{
  frameWidth = 320,
  frameHeight = 200
};

bool writePPM(const unsigned char * buf,
                unsigned width,
                unsigned height,
                const char * fileName)
{
  FILE * fileDescritor = fopen(fileName, "wb");
  if(fileDescritor)
  {
    fprintf(fileDescritor, "P6 %d %d 255 ", width, height);
    fwrite(buf, 1, width * height * 3, fileDescritor);
    fclose(fileDescritor);
    return true;
  }
  return false;
}

//Draw a black frame around the rendering buffer
void drawBlackFrame(agg::rendering_buffer& rbuf)
{
  unsigned i = 0;
  //Set lines on left and right.
  for (i = 0; i < rbuf.height(); ++i)
  {
    unsigned char * p = rbuf.row_ptr(i);
    //RGB =D
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    p += (rbuf.width() - 2) * 3;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
  }
  //Set lines on top and bottom
  memset(rbuf.row_ptr(0), 128, rbuf.width() * 3);
  memset(rbuf.row_ptr(rbuf.height() - 1), 0, rbuf.width() * 3);
}

int main()
{
  unsigned char * buffer = new unsigned char[frameWidth * frameHeight * 3];
  memset(buffer, 255, frameWidth * frameHeight * 3);

  agg::rendering_buffer rbuf(buffer,
                            frameWidth,
                            frameHeight,
                            frameWidth * 3);
  unsigned i;

  //Draw the outer black frame
  drawBlackFrame(rbuf);

  rbuf.attach(buffer + frameWidth * 3 * 20 + 3 * 20,
              frameWidth - 40,
              frameHeight - 40,
              -frameWidth * 3);
  for(i = 0; i < rbuf.height() / 2; ++i)
  {
    //Get the pointer to the beginning of the i-th row (Y-coordinate)
    unsigned char * ptr = rbuf.row_ptr(i) + i * 3;
    *ptr++ = 127;
    *ptr++ = 200;
    *ptr++ = 98;
  }

  drawBlackFrame(rbuf);
  writePPM(buffer, frameWidth, frameHeight, "agg_test.ppm");

  delete [] buffer;

  return 0;
}
