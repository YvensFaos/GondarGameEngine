#include "gsEngine.h"

#include "gsDebugGame_GameLoop.h"
#include "gsDebugGame_Graphics.h"
#include "gsDebugGame_Input.h"
#include "gsDebugGame_DataStrutures.h"
#include "gsDebugGame_Collisions.h"
#include "gsDebugGame_TextureLoading.h"

#include "gsShootEmUpGame.h"

#include "gsGGJGame.h"

#include <stdlib.h>


//Método principal do jogo
int main()
{
	gsGGJGame game;
	gsEngine engine = gsEngine(&game);

	engine.runGame();

	system("pause");
}