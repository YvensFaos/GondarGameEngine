#ifndef __CLOCK__
#define __CLOCK__

class Clock {
public:
	// Inicializa o relógio
	static void init();

	// Atualiza o relógio para o tempo atual
	static void update();

	// Retorna o tempo total de execução do jogo desde que o relógio foi inicializado
	static double getTotalTime();
	// Retorna o tempo decorrido entre as duas últimas atualizações do relógio
	static double getDeltaTime();
}

#endif