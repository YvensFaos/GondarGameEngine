#include "gsGGJLifes.h"


#include "gsSystem.h"
#include "gsGGJGlobals.h"

gsGGJLifes::gsGGJLifes(gsGGJGame* game) {
	lifeSprite = new gsSpriteSheet("GGJ\\star.png", "life", 1, 1);

	transform = gsTransform(gsVector3::zero(), LIFES_SIZE);
}
gsGGJLifes::~gsGGJLifes(void) {
	delete lifeSprite;
}

void gsGGJLifes::update() {

}
void gsGGJLifes::draw() {
	gsVector3 initialPosition = transform.position;

	lifeSprite->sendToOpenGL_Texture();
	for (int i = 0; i < gsGGJGlobal_Lifes; i++)
	{
		gsGraphics::drawQuad(transform);
		transform.position += LIFES_MARGIN;
	}

	transform.position = initialPosition;
}