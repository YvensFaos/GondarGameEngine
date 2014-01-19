#ifndef __GS_LINKEDLIST__
#define __GS_LINKEDLIST__

#include "gsNode.h"

#define generics template <class T>

generics
class gsLinkedList {
private:
	int size;

	gsNode<T>* head;
	void add(gsNode<T>* node);
	gsNode<T>* getHead(void);
public:
	gsLinkedList<T>(void);
	gsLinkedList<T>(T value);
	~gsLinkedList(void);

	T get(int i);

	void add(T value);
	void remove(int i);
	bool contains(T value);
	void clear(void);

	int getSize(void);
	void log(void);
};
#endif