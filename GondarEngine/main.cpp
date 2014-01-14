#include "glMain.h"

//Método principal do jogo
int main()
{
	//Macro de inicialização de variáveis. Esse macro inicializa os valores das variáveis principais do tamanho de janela e posicionamento inicial da câmera do OpenGL
	INIT_640x480

	//Método de inicialização do openGL
	glInitiate();

	//Início do game loop
	glLoop();

	//Finaliza a aplicação
	return glTerminate();
}