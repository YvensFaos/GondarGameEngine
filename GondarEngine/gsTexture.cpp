#include "gsTexture.h"

#include "gsOpenGL.h"
#include "gsLogger.h"

#include <stdlib.h>
#include <stdio.h>

gsTexture::gsTexture(void)
{
	width = -1;
	height = -1;
}

gsTexture::gsTexture(const char* file)
{
	unsigned char* texture = rgb_tga(file);
	loadTexture(file);
}

void gsTexture::loadTexture(const char* textureName)
{
	unsigned char* texture = rgb_tga(textureName);
	
	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle); 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureName);
}

void gsTexture::sendToOpenGL(void)
{
	glBindTexture(GL_TEXTURE_2D, handle);
}

unsigned char* gsTexture::rgb_tga(const char *filename)
{
  FILE *file = fopen(filename, "rb");
  if (file == NULL)
  {
	  char* error;
      sprintf("Could not open the file: %s\n", filename, &error);
	  GS_LOG(error);
	  
      return 0;
  }

  tga_header header;

  //read all 18 bytes of the header
  
  fread(reinterpret_cast<void*>(&header), sizeof(tga_header), 1, file);

  //should be image type 2 (color) or type 10 (rle compressed color)
  if (header.data_type != TGA_UNCOMPRESSED_RGB && header.data_type != TGA_RLE_RGB)
  {
      fclose(file);
      return 0;
  }

  if (header.id_length)
  {
      fseek(file, header.id_length, SEEK_CUR);
  }

  // get the size and bitdepth from the header
  int m_width = header.width;
  int m_height = header.height;
  int m_bpp = header.bits_per_pixel / 8;
  width = m_width;
  height = m_height;

  if (m_bpp != 3 && m_bpp != 4)
  {
      fclose(file);
      exit(0);
  }

  int imageSize = m_width * m_height * m_bpp;

  //allocate memory for image data
  unsigned char *data = new unsigned char[imageSize];

  //read the uncompressed image data if type 2
  if (header.data_type == TGA_UNCOMPRESSED_RGB)
  {
      fread(data, sizeof(char), imageSize, file);
  }

  long ctpixel = 0,
    ctloop = 0;

  //read the compressed image data if type 10
  if (header.data_type == TGA_RLE_RGB)
  {
      // stores the rle header and the temp color data
      unsigned char rle;
      unsigned char color[4];

      while (ctpixel < imageSize)
      {
	  // reads the the RLE header
	  fread(&rle, 1, 1, file);

	  // if the rle header is below 128 it means that what folows is just raw data with rle+1 pixels
	  if (rle < 128)
	  {
	      fread(&data[ctpixel], m_bpp, rle+1, file);
	      ctpixel += m_bpp*(rle+1);
	  }

	  // if the rle header is equal or above 128 it means that we have a string of rle-127 pixels
	  // that use the folowing pixels color
	  else
	  {
	      // read what color we should use
	      fread(&color[0], 1, m_bpp, file);

	      // insert the color stored in tmp into the folowing rle-127 pixels
	      ctloop = 0;
	      while (ctloop < (rle-127))
	      {
		  data[ctpixel] = color[0];
		  data[ctpixel+1] = color[1];
		  data[ctpixel+2] = color[2];
		  if (m_bpp == 4)
		  {
		      data[ctpixel+3] = color[3];
		  }

		  ctpixel += m_bpp;
		  ctloop++;
	      }
	  }
      }
  }

  ctpixel=0;

  //Because TGA file store their colors in BGRA format we need to swap the red and blue color components
  unsigned char temp;
  while (ctpixel < imageSize)
  {
      temp = data[ctpixel];
      data[ctpixel] = data[ctpixel+2];
      data[ctpixel+2] = temp;
      ctpixel += m_bpp;
  }

  //close file
  fclose(file);

  return data;
}