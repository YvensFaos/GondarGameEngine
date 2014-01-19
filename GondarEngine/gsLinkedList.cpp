#include "gsLinkedList.h"

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
void gsLinkedList<T>::add(T value)
{
	gsNode* node = new gsNode(value);
	add(node);
}

generics
void gsLinkedList<T>::add(gsNode<T>* node)
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
void gsLinkedList<T>::remove(int i)
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
bool gsLinkedList<T>::contains(T value)
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
	//A ser implementado.
}