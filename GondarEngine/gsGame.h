#ifndef __GS_GAME__
#define __GS_GAME__

class gsGame {
public:
	virtual ~gsGame() {}

	virtual void start() = 0;
	virtual void end() = 0;

	virtual bool isRunning() = 0;

	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif