#ifndef __GS_WINDOW__
#define __GS_WINDOW__

// Foward Declaration: classe Janela do GLFW
struct GLFWwindow;

// Subsitema responsável pela criação e dealocação da janela
class gsWindow {
public:
	// Inicializa a janela com a resolução indicada
	static void init(int resX, int resY);
	// Libera os recursos utilizados pela janela
	static void dispose();

	// Retorna uma referência para a janela da aplicação
	static GLFWwindow* getWindow();
};

#endif