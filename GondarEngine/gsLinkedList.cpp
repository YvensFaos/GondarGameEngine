#include "gsLinkedList.h"

generics
gsList<T>::gsList(void)
{
	head = nullptr;
	size = 0;
}

generics
gsList<T>::gsList(T value)
{
	head = new gsNode(value);
	size = 1;
}

generics
gsList<T>::~gsList(void)
{
	if(head)
	{
		clear();
		head = nullptr;
	}
}

generics
gsNode<T>* gsList<T>::getHead(void)
{
	return head;
}

generics
T gsList<T>::get(int i)
{
	if(head == nullptr || i > size)
	{
		return nullptr;
	}
	else
	{
		int counter = 0;

		gsNode<T>* actual = &head;
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
void gsList<T>::add(T value)
{
	gsNode* node = new gsNode(value);
	add(node);
}

generics
void gsList<T>::add(gsNode<T>* node)
{
	if(head == nullptr)
	{
		head = node;
	}
	else
	{
		if(head->next == nullptr)
		{
			head->next = node;
		}
		else
		{
			node->next = head->next;
			head->next = node->next;
		}
	}
	size++;
}

generics
void gsList<T>::remove(int i)
{
	if(head == nullptr || i > size)
	{
		return nullptr;
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
				return nullptr;
			}
		}

		before->next = actual->getNext();

		delete actual;

		size--;
	}
}

generics
bool gsList<T>::contains(T value)
{
	if(head == nullptr)
	{
		return nullptr;
	}
	else
	{
		gsNode<T>* actual = head;
		while(actual != nullptr)
		{
			if(actual == nullptr)
			{
				return nullptr;
			}
			if(actual->value == value)
			{
				return true;
			}

			actual = actual->getNext();
		}

		return false;
	}
}

generics
void gsList<T>::clear(void)
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
	}
}

generics
int gsList<T>::size(void)
{
	return size;
}

generics
void gsList<T>::log(void)
{
	//A ser implementado.
}