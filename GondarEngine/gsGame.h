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

/*
class A;

class A {
public:
	virtual void f() { printf("A"); }
};

class B : public A {
public:
	virtual void f() { printf("B"); }
};

void main() {
	A *obj = new B();

	obj->f();
}

*/