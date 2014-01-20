#ifndef __GS_MESH__
#define __GS_MESH__

#include "gsFilehandler.h"
#include "gsVector3.h"
#include "gsTriangle.h"

class gsMesh {
private:
	bool wireFrame;
	bool enableArrays;
	gsFileHandler* fileHandler;

public:
	int vertexesSize;
	int facesSize;

	gsVector3* vertexes;
	gsVector3* faces;
	gsTriangle* triangles;

	gsMesh(void);
	gsMesh(const char* fileName);
	~gsMesh(void);

	void setWireframe(bool);
	void drawMesh(void);

	float* splitVector3(char* line);
	gsVector3* readVector3(char* line);

private:
	void generateMesh();
};

#endif