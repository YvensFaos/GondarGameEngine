#include "gsEngine.h"
#include "gsDebugGame_Gameloop.h"

#include <stdlib.h> // system("pause");

//Método principal do jogo
int main()
{
	gsDebugGame_GameLoop game;
	gsEngine engine = gsEngine(&game);

	engine.runGame();


	system("pause");
}