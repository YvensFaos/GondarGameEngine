#include "gsEngine.h"
#include "gsDebugGame_Graphics.h"

#include <stdlib.h> // system("pause");

//Método principal do jogo
int main()
{
	gsDebugGame_Graphics game;
	gsEngine engine = gsEngine(&game);

	engine.runGame();


	system("pause");
}