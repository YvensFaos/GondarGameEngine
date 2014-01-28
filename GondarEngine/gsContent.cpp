#include "gsContent.h"


#include "gsArrayList.h"
#include "gsHashMap.h"
#include "gsOpenGL.h"
#include "FreeImage\FreeImage.h"


struct gsTexData {
	int w, h;
	GLuint handle;

	gsTexData() {}
	gsTexData(int _w, int _h, GLuint _handle) {
		w = _w; h = _h; handle = _handle;
	}
	~gsTexData() {}

	void dispose() {
		glDeleteTextures(1, &handle);
	}
};

gsHashMap<gsTexData*> gLoadedTexturesNames;
gsArrayList<gsTexData> gLoadedTextures;

void gsContent::init() {
	gLoadedTextures.~gsArrayList();
	new(&gLoadedTextures)gsArrayList<gsTexData>(32);
}
void gsContent::dispose() {

}


int* gsContent::getTexture(const char* name) {
	if (!gLoadedTexturesNames.contains((int)name)) {
		FREE_IMAGE_FORMAT fif;

		fif = FreeImage_GetFIFFromFilename(name);

		gsAssert(fif != FIF_UNKNOWN);

		FIBITMAP *bitmap = FreeImage_Load(fif, name);
		FIBITMAP *temp = bitmap;
		bitmap = FreeImage_ConvertTo32Bits(temp);
		FreeImage_Unload(temp);

		int width = FreeImage_GetWidth(bitmap);
		int height = FreeImage_GetHeight(bitmap);

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
		GLuint handle;
		glGenTextures(1, &handle);
		glBindTexture(GL_TEXTURE_2D, handle); 
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		delete texture;
		FreeImage_Unload(bitmap);

		gLoadedTextures.add(gsTexData(width, height, handle));
		gLoadedTexturesNames.add((int)name, gLoadedTextures.getAddress(gLoadedTextures.getSize() - 1));

		GS_LOG(gLoadedTextures.getSize());
	}
	return (int*)gLoadedTexturesNames.get((int)name);
}