#ifndef __GS_HASHMAP__
#define __GS_HASHMAP__

#include "gsArrayList.h"
#include "gsKeyValue.h"
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
gsHashMap<T>::gsHashMap(void)
{
	int size = chunk;
	data = new gsArrayList<gsKeyValue<T>>[size];
}

generics
gsHashMap<T>::gsHashMap(int size)
{
	data = new gsArrayList<gsKeyValue<T>>[size];
}

generics
gsHashMap<T>::~gsHashMap(void)
{
	delete[] data;
}

generics
T gsHashMap<T>::get(int key)// TODO; O get do hash funciona de forma diferente do get do arraylist, ou seja, precisa de uma implementacao especifica.
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<T>>* list = &data[position];
	
	int listSize = list->getSize();

	for (int i = 0; i < listSize; i++)
	{
		if (list->get(i).key == key)
		{
			return list->get(i);
		}
	}

	return nullptr;

	//return data[hashFunction(key)].get(key);
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

	if(list->getSize() > 1)
	{
		GS_LOG("Overflow de Bucket");
	}
}

generics
void gsHashMap<T>::remove(int key)
{
	data[hashFunction(key)].remove(key);
}

generics
bool gsHashMap<T>::contains(int key) //TODO ; Não tenho certeza se a implementação seria assim. Está dando um erro "cannot access private member declared in class: 'gsKeyValue<T>' ".
{
	int position = hashFunction(key);
	gsArrayList<gsKeyValue<T>>* list = &data[position];
	
	return list->contains(gsKeyValue<T>(key, 000));

	//return data[hashFunction(key)].getSize() > 0;

	/*Usar o resultado da função hash para saber a possivel localização desse valor no hashmap
	para depois procurar no ArrayList daquela posição se o valor existe.
	*/
}

generics
void gsHashMap<T>::clear(void)
{
	//I'm 12 and what is this..
}

#undef generics
#undef chunk
#endif