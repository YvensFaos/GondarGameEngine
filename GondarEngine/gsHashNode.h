#ifndef __GS_HASHNODE__
#define __GS_HASHNODE__

#define generics template <class T>

generics
class gsHashNode{
public:
	T value;
	int key;

	gsHashNode* next;

private:
	gsHashNode<T>(void);
	gsHashNode<T>(int key, T value);
	~gsHashNode<T>(void);

	gsHashNode<T>* getNext(void);
	void setNext(gsHashNode<T>* next);

	T getValue(void);
	void setValue(T value);

	int getKey(void);
	void setKey(int key);
};

generics
gsHashNode<T>::gsHashNode(void)
{
	this->key = nullptr;
	this->value = nullptr;
	this->next = nullptr;
}

generics
gsHashNode<T>::gsHashNode(int key, T value)
{
	this->key = key;
	this->value = value;
	this->next = nullptr;
}

generics
gsHashNode<T>::~gsHashNode(void)
{


}

generics
gsHashNode<T>* gsHashNode<T>::getNext(void)
{

	return this->next;
}

generics
void gsHashNode<T>::setNext(gsHashNode<T>* next)
{
	this->next = next;
}

generics
T gsHashNode<T>::getValue()
{
	return value;
}

generics
void gsHashNode<T>::setValue(T value)
{
	this->value = value;
}

generics
int gsHashNode<T>::getKey()
{
	return key;
}

generics
void gsHashNode<T>::setKey(int key)
{
	this->key = key;
}

#undef generics
#endif