#ifndef __GS_GAME_OBJECT__
#define __GS_GAME_OBJECT__


// Classe base de todos os objetos do jogo.
class gsGameObject {
private:
	bool enabled;   // Se enabled for true, o objeto é atualizado todo frame
	bool visible;   // Se visible for true, o objeto é desenhado todo frame
	bool collident; // Se collident for true, o objeto é testado por colisões
	bool solid;     // Se solid for true, ele não entrará dentro de outros objetos quando houver colisão

	// Flags para criar filtrar quais objetos colidem com quais outros objetos.
	int collisionMask;

public:
	gsGameObject() {
		enabled = visible = collident = solid = true;
		collisionMask = 0xFFFFFFFF; // todos os bits 1.
	}

	virtual void update() = 0;
	virtual void draw() = 0;

	bool isEnabled() { return enabled; }
	bool isVisible() { return visible; }
	bool isCollident() { return collident; }
	bool isSolid() { return solid; }
};

#endif