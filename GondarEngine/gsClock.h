#ifndef __GS_CLOCK__
#define __GS_CLOCK__

// Subsistema responsável pelo registro da passagem do tempo durante a execução
class gsClock {
public:
	// Inicializa o relógio
	static void init();

	// Atualiza o relógio para o tempo atual
	static void update();

	// Retorna o tempo total de execução do jogo desde que o relógio foi inicializado (em segundos)
	static double getTotalTime();
	// Retorna o tempo decorrido entre as duas últimas atualizações do relógio (em segundos)
	static double getDeltaTime();
};

#endif