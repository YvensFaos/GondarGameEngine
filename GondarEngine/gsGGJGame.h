#ifndef __GS_GGJ_GAME__
#define __GS_GGJ_GAME__


#include "gsGame.h"
#include "gsGameObject.h"
#include "gsArrayList.h"


class gsGGJGame : public gsGame {
private:
	gsArrayList<gsGameObject*> objects;
	gsArrayList<gsGameObject*> objectsToBeRemoved;
	
public:
	virtual void start();
	virtual void end();

	virtual bool isRunning();

	virtual void update();
	virtual void draw();

	void addObjetToObjectsList(gsGameObject* object);
	void removeObjectFromObjectsList(gsGameObject *object);
};

#endif