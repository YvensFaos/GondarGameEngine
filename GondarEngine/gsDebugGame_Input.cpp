#include "gsDebugGame_Input.h"

#ifdef GS_DEBUG

#include "gsLogger.h"
#include "gsInput.h"
#include "gsGraphics.h"
#include "gsOpenGL.h"


class gsDebugInputObject : public gsGameObject {
public:
	int key;
	gsDebugInputObject(int i) {
		key = i;

		int row = i / 30;
		int col = i % 30;

		gsVector3 position = gsVector3(col * 25 + 20, row * 25 + 20, 0);

		gsVector3 size = gsVector3(20, 20, 0);
		gsColor color = gsColor::cyan(0.7);

		transform = gsTransform(position, size, color);
	}

	void update() {
		if (gsInput::queryKey(key) == gsKeyState::Pressed) {
			transform.tint = gsColor::red();
		} else if (gsInput::queryKey(key) == gsKeyState::JustPressed) {
			transform.tint = gsColor::magenta();
		} else if (gsInput::queryKey(key) == gsKeyState::JustReleased) {
			transform.tint = gsColor::blue();
		} else {
			transform.tint = gsColor::cyan();
		}
	}
	void draw() {
		gsGraphics::drawQuad(transform);
	}

	void onCollision(gsGameObject *other, const gsCollisionInfo& info) {}
};

void gsDebugGame_Input::start() {
	GS_LOG("Teste Inicializado\n");
	for (int i = 32; i < 97; i++)
	{
		objects.add(new gsDebugInputObject(i));
	}
	objects.add(new gsDebugInputObject(161));
	objects.add(new gsDebugInputObject(162));
	for (int i = 256; i < 349; i++)
	{
		objects.add(new gsDebugInputObject(i));
	}
}
void gsDebugGame_Input::end() {
	GS_LOG("Teste Finalizado");
	for (int i = 0; i < objects.getSize(); i++)
	{
		delete objects.get(i);
	}
}

bool gsDebugGame_Input::isRunning() {
	return true;
}

void gsDebugGame_Input::update() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->update();
	}
}
void gsDebugGame_Input::draw() {
	for (int i = 0; i < objects.getSize(); i++)
	{
		objects.get(i)->draw();
	}
}

#endif