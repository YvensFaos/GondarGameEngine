#include "gsDebugGame_Gameloop.h"

#ifdef GS_DEBUG

#include "gsLogger.h"
#include "gsClock.h"
#include "gsRandom.h"


void gsDebugGame_GameLoop::start() {
	GS_LOG("Teste Inicializado\n");
	frameCounter = 0;
}
void gsDebugGame_GameLoop::end() {
	float time = gsClock::getTotalTime();
	float fps = frameCounter / time;

	// O código asseguir é um teste do gerador de números aleatórios.
	// Ele vai basicamente gerar números aleatórios usando as 4 funções de random e vai calcular
	// a média de cada função.

	GS_LOG("\nTeste finalizado. Os valores a seguir devem ser aproximadamente: 60, 0.5 e 60");
	GS_LOG("Frames: " << frameCounter);
	GS_LOG("Tempo total: " << time);
	GS_LOG("FPS: " << fps << "\n\n");

	GS_LOG("Testando números aleatórios, as colunas são: nextBool, nextInt, nextDouble e chance(50): ");
	int samplesCount = 1000;
	double meanBool = 0.0f;
	double meanInt = 0.0f;
	double meanDouble = 0.0f;
	double meanChance = 0.0f;
	bool rb; int ri; double rd; bool rc;
	for (int i = 0; i < samplesCount; i++)
	{
		rb = gsRandom::nextBool();
		ri = gsRandom::nextInt(-50, 50);
		rd = gsRandom::nextDouble();
		rc = gsRandom::chance(50);

		meanBool += (int)rb;
		meanInt += ri;
		meanDouble += rd;
		meanChance += (int)rc;

		GS_LOG(rb << ", " << ri << ", " << rd << ", " << rc);
	}
	
	meanBool /= samplesCount;
	meanInt /= samplesCount;
	meanDouble /= samplesCount;
	meanChance /= samplesCount;

	GS_LOG("Média de cada coluna: (valores esperados: 0,5, 0, 0,5 e 0,5 (aproximadamente))");
	GS_LOG(meanBool << ", " << meanInt << ", " << meanDouble << ", " << meanChance);
}

bool gsDebugGame_GameLoop::isRunning() {
	return frameCounter < 60;
}

void gsDebugGame_GameLoop::update() {
	GS_LOG("Frame: " << frameCounter << ", delta time: " << gsClock::getDeltaTime());
	frameCounter++;
}
void gsDebugGame_GameLoop::draw() {
	// nada
}

#endif