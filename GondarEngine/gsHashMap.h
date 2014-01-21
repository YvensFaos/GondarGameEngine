#ifndef __GS_HASHMAP__
#define __GS_HASHMAP__

#include "gsArrayList.h"
#define generics template <class T>

#define chunk 256

generics
class gsHashMap {
private:
	gsArrayList<T>* data;
	int size;

public:
	gsHashMap<T>(void);
	gsHashMap<T>(int size);
	~gsHashMap<T>(void);

	T get(int value);

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
	data = new gsArrayList<T>[size];
}

generics
gsHashMap<T>::gsHashMap(int size)
{
	data = new gsArrayList<T>[size];
}

generics
gsHashMap<T>::~gsHashMap(void)
{
	delete[] data;
}

generics
T gsHashMap<T>::get(int value)
{
	return data[hashFunction(value)][0];
	//Retorna o objeto T que esta no ArrayList da posicao indicada pela funcao hash
	//Usar o resultado da função de hash, mas a função vai depender do tipo de key do hashmap ?
}

generics
int gsHashMap<T>::hashFunction(int value)
{
	return value % size; //Função simples para testes.
}

generics
void gsHashMap<T>::add(int key, T value)
{
	int hash = hashFunction(key);
	gsArrayList<T>* list = &data[hash];
	list->add(value);

	if(list->getSize() > 1)
	{
		GS_LOG("Overflow de Bucket");
	}
}

generics
void gsHashMap<T>::remove(int key)
{
	data[hashFunction(key)].clear();
}

generics
bool gsHashMap<T>::contains(int key)
{
	return data[hashFunction(key)].getSize() > 0;

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