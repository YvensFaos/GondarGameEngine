#ifndef __GS_TEXTURE__
#define __GS_TEXTURE__

typedef unsigned int GLuint;

/* Image type (data_type)
 *
 * CMI   - "Color Mapped Image"
 * RGB   - "Red, Green, and Blue"
 * BW    - "Black and White"
 * RLE   - "Run Length Encoded"
 * HDRLE - "Huffman, Delta, and Run Length Encoded"
 * QUAD  - "4 pass quadtree-type process"
 */
#define TGA_NONE 0
#define TGA_UNCOMPRESSED_CMI 1
#define TGA_UNCOMPRESSED_RGB 2
#define TGA_UNCOMPRESSED_BW 3
#define TGA_RLE_CMI 9
#define TGA_RLE_RGB 10
#define TGA_COMPRESSED_BW 11
#define TGA_COMPRESSED_CMI_HDRLE 32
#define TGA_COMPRESSED_CMI_HDRLE_QUAD 33

struct tga_header
{
  unsigned char  id_length;
  unsigned char  colour_map_type;
  unsigned char  data_type;
  unsigned short colour_map_origin;
  unsigned short colour_map_length;
  unsigned char  colour_map_depth;
  unsigned short x_origin;
  unsigned short y_origin;
  unsigned short width;
  unsigned short height;
  unsigned char  bits_per_pixel;
  unsigned char  image_descriptor;
};

// Classe que encapsula uma textura do opengl
class gsTexture {
private:
	GLuint handle; // Handle para a textura criado pelo opengl

	void loadTexture(const char* textureName);
	unsigned char* rgb_tga(const char *filename);
public:
	int width;
	int height;

	gsTexture(void);
	gsTexture(const char* file);

	// torna a textura ativa
	void sendToOpenGL(void);
};

#endif