#include <stdio.h>
#include <string.h>

#include "agg_pixfmt_rgb.h"
#include "agg_pixfmt_amask_adaptor.h"
#include "agg_alpha_mask_u8.h"

enum
{
  frameWidth = 320,
  frameHeight = 200
};

bool write_ppm(unsigned const char * buf,
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

int main(int argc, char ** argv)
{
  //Allocate the main rendering buffer and clear it
  agg::int8u * buffer = new agg::int8u[frameWidth * frameHeight * 3];
  memset(buffer, 0, frameWidth * frameHeight * 3);
  agg::rendering_buffer rbuf (buffer,
                              frameWidth,
                              frameHeight,
                              frameWidth * 3);
  agg::pixfmt_rgb24 pixf(rbuf);

  //Allocate the aplha-mask buffer, create the rendering buffer object
  agg::int8u * amask_buf = new agg::int8u[frameWidth * frameHeight];
  agg::rendering_buffer amask_rbuf(amask_buf,
                                  frameWidth,
                                  frameHeight,
                                  frameWidth);
  agg::amask_no_clip_gray8 amask(amask_rbuf);

  // Create the alpha-mask adaptor attached to the alpha-mask object
  agg::pixfmt_amask_adaptor<agg::pixfmt_rgb24, 
                            agg::amask_no_clip_gray8> pixf_amask(pixf, amask);

  //Drw somthing in the alpha-mask buffer
  unsigned i;
  printf("-- %d \n", frameHeight);
  for (i = 0; i < frameHeight; ++i)
  {
    unsigned val = 255 * i / frameHeight;
    printf("%d, ", val);
    memset(amask_rbuf.row_ptr(i), val, frameWidth);
  }
  puts("");

  //Draw the spectrum
  agg::rgba8 span[frameWidth];

  for (i = 0; i < frameWidth; ++i)
  {
    agg::rgba c(380.0 + 400.0 * i / frameWidth, 0.8);
    span[i] = agg::rgba8(c);
  }

  for (i = 0; i < frameHeight; ++i)
  {
    pixf_amask.blend_color_hspan(0, i, frameWidth, span, 0);
  }

  write_ppm(buffer, frameWidth, frameHeight, "agg_test.ppm");

  delete [] amask_buf;
  delete [] buffer;

  return 0;
}
