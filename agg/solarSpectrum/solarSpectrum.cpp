#include <stdio.h>
#include <string.h>
#include "agg_pixfmt_rgb.h"

enum
{
  frameWidth = 320,
  frameHeight = 200
};

bool writePPM (unsigned const char * buf,
              unsigned width,
              unsigned height,
              const char * path)
{
  FILE * fileDescriptor = fopen(path, "wb");

  if (fileDescriptor)
  {
    fprintf(fileDescriptor, "P6 %d %d 255 ", width, height);
    fwrite(buf, 1, width * height * 3, fileDescriptor);
    fclose(fileDescriptor);
  }

  return false;
}

int main()
{
  //Allocate the buffer.
  unsigned char * buffer = new unsigned char[frameWidth * frameHeight * 3];

  //Clear the buffer, manually
  memset(buffer, 255, frameWidth * frameHeight * 3);

  //Create the rendering buffer object
  agg::rendering_buffer rbuf(buffer, frameWidth, frameHeight, frameWidth * 3);
  
  //Create the Pixel format renderer
  agg::pixfmt_rgb24 pixf(rbuf);

  //Create one line (span) of type rgba8
  agg::rgba8 span[frameWidth];

  //Fill the buffer using blender color
  unsigned i;
  puts("Span...");
  for (i = 0; i < frameWidth; ++i)
  {
    agg::rgba c(380.0 + 400.0 * i / frameWidth, 0.8);
    span[i] = agg::rgba8(c);
  }

  for (i = 0; i < frameHeight; ++i)
  {
    pixf.blend_color_hspan(0, i, frameWidth, span, 0, 255);
  }
  puts("write...");
  writePPM(buffer, frameWidth, frameHeight, "agg_test.ppm");

  delete [] buffer;
  return 0;
}
