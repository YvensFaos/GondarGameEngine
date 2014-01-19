#include "gsEngine.h"

#include "gsDebugGame_Gameloop.h"
#include "gsDebugGame_Graphics.h"
#include "gsDebugGame_DataStrutures.h"


#include <stdlib.h> // system("pause");

//Método principal do jogo
int main()
{
	gsDebugGame_DataStrutures game;
	gsEngine engine = gsEngine(&game);

	engine.runGame();


	system("pause");
}