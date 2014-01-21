#include "gsTexture.h"

#include "gsOpenGL.h"
#include "gsLogger.h"
#include "gsMacros.h"

#include "FreeImage\FreeImage.h"

#include <stdlib.h>
#include <stdio.h>

gsTexture::gsTexture(void)
{
	width = -1;
	height = -1;
}

gsTexture::gsTexture(const char* file)
{
	loadTexture(file);
}

void gsTexture::loadTexture(const char* textureName)
{
	FREE_IMAGE_FORMAT fif;

	fif = FreeImage_GetFIFFromFilename(textureName);

	bool test = fif != FIF_UNKNOWN;
	gsAssert(test);

	FIBITMAP *bitmap = FreeImage_Load(fif, textureName);
	FIBITMAP *temp = bitmap;
	bitmap = FreeImage_ConvertTo32Bits(temp);
	FreeImage_Unload(temp);

	width = FreeImage_GetWidth(bitmap);
	height = FreeImage_GetHeight(bitmap);

	gsAssert(width > 0 && height > 0);
	
	GLubyte *texture = new GLubyte[4 * width * height];
	char *bitmapData = (char*)FreeImage_GetBits(bitmap);
	for (int i = 0; i < width * height; i++)
	{
		texture[i * 4 + 0] = bitmapData[i * 4 + 2];
		texture[i * 4 + 1] = bitmapData[i * 4 + 1];
		texture[i * 4 + 2] = bitmapData[i * 4 + 0];
		texture[i * 4 + 3] = bitmapData[i * 4 + 3];
	}

	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle); 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	FreeImage_Unload(bitmap);
}

void gsTexture::sendToOpenGL(void)
{
	glBindTexture(GL_TEXTURE_2D, handle);
}
