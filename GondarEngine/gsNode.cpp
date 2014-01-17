#include "gsNode.h"

generics
gsNode<T>::gsNode(void)
{
	this->value = nullptr;
}

generics
gsNode<T>::gsNode(T value)
{
	this->value = value;
}

generics
gsNode<T>::~gsNode(void)
{
	if(T)
	{
		delete T;
	}
}

generics
gsNode<T>* gsNode<T>::getNext(void)
{
	return next;
}

generics
void gsNode<T>::setNext(gsNode<T>* next)
{
	this->next = next;
}

generics
T gsNode<T>::getValue(void)
{
	return T;
}

generics
void gsNode<T>::setValue(T value)
{
	this->T = value;
}