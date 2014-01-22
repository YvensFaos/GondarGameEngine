#include "gsEngine.h"

#include "gsDebugGame_GameLoop.h"
#include "gsDebugGame_Graphics.h"
#include "gsDebugGame_Input.h"
#include "gsDebugGame_DataStrutures.h"
#include "gsDebugGame_Collisions.h"
#include "gsDebugGame_TextureLoading.h"

#include <stdlib.h> // system("pause");

//Método principal do jogo
int main()
{
	gsDebugGame_Collisions game;
	gsEngine engine = gsEngine(&game);

	engine.runGame();

	//system("pause");
}