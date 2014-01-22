#ifndef __GS_HASHMAP__
#define __GS_HASHMAP__

#include "gsArrayList.h"
#include "gsKeyValue.h"
#include "gsMacros.h"

#define generics template <class T>
#define chunk 256

generics
class gsHashMap {
private:
	gsArrayList<gsKeyValue<T>>* data;
	int size;

public:
	gsHashMap<T>(void);
	gsHashMap<T>(int size);
	~gsHashMap<T>(void);

	T get(int key);

	int hashFunction(int key);

	void add(int key, T value);
	void remove(int key);
	bool contains(int key);
	void clear(void);
};

generics
gsHashMap<T>::gsHashMap(void) {
	data = new gsArrayList<gsKeyValue<T>>[chunk];
	this->size = chunk;
}

generics
gsHashMap<T>::gsHashMap(int size) {
	data = new gsArrayList<gsKeyValue<T>>[size];
	this->size = chunk;
}

generics
gsHashMap<T>::~gsHashMap(void) {
	delete[] data;
}

generics
T gsHashMap<T>::get(int key) {
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<T>>* list = &data[position];
	
	for (int i = 0; i < list->getSize(); i++)
	{
		if (list->get(i).key == key)
		{
			return list->get(i).value;
		}
	}
	gsAssert(0); // Element not found Exception
	return T();
}

generics
int gsHashMap<T>::hashFunction(int value)
{
	return value % size; //Função simples para testes.
}

generics
void gsHashMap<T>::add(int key, T value)
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<T>>* list = &data[position];

	list->add(gsKeyValue<T>(key,value));
}

generics
void gsHashMap<T>::remove(int key)
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<T>>* list = &data[position];
	
	for (int i = 0; i < list->getSize(); i++)
	{
		if (list->get(i).key == key)
		{
			list->remove(i);
			return;
		}
	}
	gsAssert(0); // Element not found Exception
}

generics
bool gsHashMap<T>::contains(int key)
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<T>>* list = &data[position];
	
	return list->contains(gsKeyValue<T>(key, 0));
}

generics
void gsHashMap<T>::clear(void)
{
	gsArrayList<gsKeyValue<T>>* list;
	for (int i = 0; i < size; i++)
	{
		list = &data[i];
		list->clear();
	}
}

#undef generics
#undef chunk
#endif