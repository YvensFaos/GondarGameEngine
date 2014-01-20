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

generics
gsLinkedList<T>::gsLinkedList(void)
{
	head = nullptr;
	size = 0;
}

generics
gsLinkedList<T>::gsLinkedList(T value)
{
	head = new gsNode(value);
	size = 1;
}

generics
gsLinkedList<T>::~gsLinkedList(void)
{
	if(head)
	{
		clear();
		head = nullptr;
	}
}

generics
gsNode<T>* gsLinkedList<T>::getHead(void)
{
	return head;
}

generics
T gsLinkedList<T>::get(int i)
{
	if(head == nullptr || i > size)
	{
		return nullptr;
	}
	else
	{
		int counter = 0;

		gsNode<T>* actual = head;
		while(counter++ <= i)
		{
			actual = actual->getNext();
			if(actual == nullptr)
			{
				return nullptr;
			}
		}

		return actual->getValue();
	}
}

generics
void gsLinkedList<T>::add(T value)
{
	gsNode<T>* node = new gsNode<T>(value);
	add(node);
}

generics
void gsLinkedList<T>::add(gsNode<T>* node)
{
	node->setNext(head);
	head = node;
	size++;
}

generics
void gsLinkedList<T>::remove(int i)
{
	if(head == nullptr || i > size)
	{
		return;
	}
	if(i == 0)
	{
		head = head->getNext();
	}
	else
	{
		int counter = 0;

		gsNode<T>* actual = head;
		gsNode<T>* before = nullptr;
		while(counter++ <= i)
		{
			before = actual;
			actual = actual->getNext();
			if(actual == nullptr)
			{
				return;
			}
		}

		before->setNext(actual->getNext());

		delete actual;
	}
	size--;
}

generics
bool gsLinkedList<T>::contains(T value)
{
	if(head == 0)
	{
		return false;
	}
	else
	{
		gsNode<T>* actual = head;
		while(actual != 0)
		{
			if(actual == 0)
			{
				return false;
			}
			if(actual->getValue() == value)
			{
				return true;
			}

			actual = actual->getNext();
		}

		return false;
	}
}

generics
void gsLinkedList<T>::clear(void)
{
	if(head == nullptr)
	{
		return;
	}
	else
	{
		gsNode<T>* actual = head;
		gsNode<T>* deleted = nullptr;

		while(actual != nullptr)
		{
			deleted = actual;
			actual = actual->getNext();

			delete deleted;
			size--;
		}

		head = nullptr;
		size = 0;
	}
}

generics
int gsLinkedList<T>::getSize(void)
{
	return size;
}

generics
void gsLinkedList<T>::log(void)
{
	if (size == 0) {
		GS_LOG("Lista vazia");
		return;
	}

	GS_LOG("Logging a lista inteira: ");
	gsNode<T>* actual = head;
	for (int i = 0; i < size; i++)
	{
		GS_LOG(i << ": " << actual->getValue());
		actual = actual->getNext();
	}
}

#undef generics
#endif