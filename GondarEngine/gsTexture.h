#ifndef __GS_TEXTURE__
#define __GS_TEXTURE__

typedef unsigned int GLuint;

// Classe que encapsula uma textura do opengl
class gsTexture {
private:
	GLuint handle; // Handle para a textura criado pelo opengl

	void loadTexture(const char* textureName);
	
public:
	int width;
	int height;

	gsTexture(void);
	gsTexture(const char* file);

	// torna a textura ativa
	void sendToOpenGL_Texture(void);
};

#endif