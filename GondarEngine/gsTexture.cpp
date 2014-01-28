#include "gsTexture.h"

#include "gsOpenGL.h"
#include "gsLogger.h"
#include "gsMacros.h"
#include "gsContent.h"

#include "FreeImage\FreeImage.h"

#include <stdlib.h>
#include <stdio.h>

gsTexture::gsTexture(void)
{
	width = -1;
	height = -1;
	name = "Unloaded Image";
}

gsTexture::gsTexture(const char* file, const char* name)
{
	loadTexture(file);
	this->name = name;
}
gsTexture::gsTexture(const char* name, GLuint handle, int width, int height) {
	this->name = name;
	this->handle = handle;
	this->width = width;
	this->height = height;
}
gsTexture::~gsTexture() {}

void gsTexture::loadTexture(const char* textureName)
{
	int *data = gsContent::getTexture(textureName);
	width = data[0];
	height = data[1];
	handle = data[2];
}

void gsTexture::sendToOpenGL_Texture(void)
{
	glBindTexture(GL_TEXTURE_2D, handle);
}
