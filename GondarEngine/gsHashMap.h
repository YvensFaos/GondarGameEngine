#ifndef __GS_HASHMAP__
#define __GS_HASHMAP__

#include "gsArrayList.h"
#define generics template <class T>


generics
class gsHashMap {
private:
	T* data;
	int size;

public:
	gsHashMap<T>(int size);
	~gsHashMap<T>(void);

	T get(int i);

	void add(T value);
	void remove(int i);
	bool contains(T value);
	void clear(void);
};


generics
gsHashMap<T>::gsHashMap(int size)
{
	this->data = new T[size];
	
	for (size_t i = 0; i < size; i++)
	{
		data[i] = new gsArrayList();
	}
}

generics
gsHashMap<T>::~gsHashMap(void)
{
	delete[] data;
}

generics
T gsHashMap<T>::get(int i)
{
	//Usar o resultado da função de hash, mas a função vai depender do tipo de key do hashmap ?
}

generics
void gsHashMap<T>::add(T value)
{
	//Usar o retorno da função get(int i);
}

generics
void gsHashMap<T>::remove(int i)
{ 

}

generics
bool gsHashMap<T>::contains(T value)
{
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
#endif