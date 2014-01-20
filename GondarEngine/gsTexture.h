#ifndef __GS_TEXTURE__
#define __GS_TEXTURE__


// Classe que encapsula uma textura do opengl
class gsTexture {
private:
	int handle; // Handle para a textura criado pelo opengl
public:
	int width;
	int height;

	gsTexture() {}
	gsTexture(const char* file);

	// torna a textura ativa
	void sendToOpenGL();
};

#endif