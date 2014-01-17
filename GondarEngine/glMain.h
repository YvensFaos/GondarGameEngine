#ifndef __GS_GLMAIN__
#define __GS_GLMAIN__

#include <stdlib.h>
#include <stdio.h>

#include "gsIncludeOpenGL.h"
#include "gsCamera.h"
#include "gsGeometric.h"
#include "gsInput.h"

bool rotation = false;
float ratio;
int width, height;
int windowPosX, windowPosY;

GLFWwindow* window;
gsCamera* camera;

Point3D* position;
Point3D* lookAt;
Point3D* up;

//Macros de inicialização
//Largura da tela, Altura da Tela, Posição X da Tela, Posição Y da Tela, Posição da Câmera, Direção da Câmera, Rotação da Câmera, Instanciação da Câmera, Chamada ao método de inicialização da Câmera

//Macro de janela tamanho 640x480
#define INIT_640x480 width = 640; \
	height = 480; \
	windowPosX = 800; \
	windowPosY = 100; \
	position = new Point3D(1.0f, 3.0f, 12.0f);\
	lookAt = new Point3D(0.0f, 0.0f, 0.0f);\
	up = new Point3D(0.0f, 1.0f, 0.0f);\
	camera = new gsCamera(position, lookAt, up);\
	camera->initCamera(0.0f, 50.0f, 45.0f);

//Macro de janela tamanho 800x600
#define INIT_800x600 width = 800; \
	height = 600; \
	windowPosX = 800; \
	windowPosY = 100; \
	position = new Point3D(1.0f, 3.0f, 12.0f);\
	lookAt = new Point3D(0.0f, 0.0f, 0.0f);\
	up = new Point3D(0.0f, 1.0f, 0.0f);\
	camera = new Camera(position, lookAt, up);\
	camera->initCamera(0.0f, 50.0f, 45.0f);

//Método draw genérico da engine
static void draw(void)
{

}

//Método de update genérico da engine
static void update(void)
{

}

//Definição do modelo de iluminação da aplicação
void setLightModel()
{
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0f);
}

//Método de inicialização do openGL
void glInitiate()
{

	//Setando o modelo de iluminação da janela
	setLightModel();
}

//Game Loop
void glLoop()
{
}
    
//Método de finalização da engine
int glTerminate()
{
	return 0;
}

#endif