#ifndef __GLLINKEDLIST__
#define __GLLINKEDLIST__

#include "gsNode.h"

#define generics template <class T>

generics
class gsList
{
private:
	int size;

	gsNode<T>* head;
	void add(gsNode<T>* node);
	gsNode<T>* getHead(void);
public:
	gsList<T>(void);
	gsList<T>(T value);
	~gsList(void);

	T get(int i);

	void add(T value);
	void remove(int i);
	bool contains(T value);
	void clear(void);

	int getSize(void);
	void log(void);
};
#endif