#ifndef __GLMAIN__
#define __GLMAIN__

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <GL\GLU.h>

#include "GLFW\glfw3.h"
#include "camera.h"
#include "geometric.h"
#include "glInput.h"

bool rotation = false;
float ratio;
int width, height;
int windowPosX, windowPosY;

GLFWwindow* window;
Camera* camera;

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
	camera = new Camera(position, lookAt, up);\
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

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

//Método do openGL para tratamento de input
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Chamada ao método da engine para tratamento de input
	GlInput::key_callback(window, key, scancode, action, mods);
}

//Definição do modelo de iluminação da aplicação
void setLightModel()
{
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20.0f);
}

//Método de inicialização do openGL
void glInitiate()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
	{
        exit(EXIT_FAILURE);
	}

	//Criação da janela de renderização
	window = glfwCreateWindow(width, height, "Gondar Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

	//Setando o método de tratamento de input
    glfwSetKeyCallback(window, key_callback);
   
    glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;

	glfwSetWindowPos(window, windowPosX, windowPosY);

	//Setando o modelo de iluminação da janela
	setLightModel();
}

//Game Loop
void glLoop()
{
	while (!glfwWindowShouldClose(window))
    {
		glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

		gluPerspective(camera->ffov, ratio, camera->fnear, camera->ffar);
		camera->cameraLookAt();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

		//Chamada aos principais métodos da engine
		update();
        draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
    
//Método de finalização da engine
int glTerminate()
{
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

	return 0;
}

#endif