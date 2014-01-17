#ifndef __GS_RANDOM__
#define __GS_RANDOM__

// Subsistema responsável pela geração de números aleatórios
class gsRandom {
public:
	// Inicializa o gerador de números aleatórios
	static void init();

	// retorna um valor booleano aleatório
	static bool nextBool();
	// retorna um valor inteiro aleatório no intervalo [min, max]
	static int nextInt(int min, int max);
	// retorna um valor decimal aleatório entre 0 e 1
	static double nextDouble();

	// gera um valor de 0 a 100 e se esse valor for maior que "chance" retorna true
	static bool chance(int chance);
};

#endif