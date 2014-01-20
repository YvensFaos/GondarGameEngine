#ifndef __GS_NODE__
#define __GS_NODE__

#define generics template <class T>

generics
class gsNode {
private:
	T value;
	gsNode* next;
	
public:
	gsNode<T>(void);
	gsNode<T>(T value);
	~gsNode<T>(void);

	gsNode<T>* getNext(void);
	void setNext(gsNode<T>* next);

	T getValue(void);
	void setValue(T value);
};

generics
gsNode<T>::gsNode(void)
{
	this->value = nullptr;
	this->next = nullptr;
}

generics
gsNode<T>::gsNode(T value)
{
	this->value = value;
	this->next = nullptr;
}

generics
gsNode<T>::~gsNode(void)
{

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
	return value;
}

generics
void gsNode<T>::setValue(T value)
{
	this->T = value;
}

#undef generics
#endif