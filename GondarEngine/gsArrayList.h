#ifndef __GS_ARRAY_LIST__
#define __GS_ARRAY_LIST__


#define chunkSize 16
#define generics template <class T>

#include "gsLogger.h"
#include "gsMacros.h"

generics
class gsArrayList {
private:
	T*  data;
	int capacity;
	int size;

public:
	gsArrayList<T>(void);
	gsArrayList<T>(int initialCapacity);
	~gsArrayList(void);

	T get(int i);
	T* getAddress(int i);

	void add(T value);
	void remove(int i);
	bool contains(T value);
	int  indexOf(T value);
	void clear(void);

	int getSize(void) { return size; }
	int getCapacity(void) { return capacity; }
	void log(void);
};


generics
gsArrayList<T>::gsArrayList() {
	capacity = chunkSize;
	size = 0;
	data = new T[capacity];
}

generics
gsArrayList<T>::gsArrayList(int initialCapacity) {
	capacity = initialCapacity;
	size = 0;
	data = new T[capacity];
}

generics
gsArrayList<T>::~gsArrayList(void) {
	delete[] data;
}

generics
T gsArrayList<T>::get(int i) {
	if (i < 0 || i >= size) {
		gsAssert(0); // Array out of bounds exception
	}
	return data[i];
}

generics
	T* gsArrayList<T>::getAddress(int i) {
	if (i < 0 || i >= size) {
		gsAssert(0); // Array out of bounds exception
	}
	return &data[i];
}

generics
void gsArrayList<T>::add(T value) {
	if (size == capacity) {
		capacity += chunkSize;
		T* newData = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	data[size] = value;
	size++;
}

generics
void gsArrayList<T>::remove(int i) {
	if (i < 0 || i >= size) {
		gsAssert(0); // Array out of bounds exception
	}
	size--;
	for (; i < size; i++)
	{
		data[i] = data[i + 1];
	}
}

generics
bool gsArrayList<T>::contains(T value) {
	return (indexOf(value) != -1);
}

generics
int gsArrayList<T>::indexOf(T value) {
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value) {
			return i;
		}
	}
	return -1;
}

generics
void gsArrayList<T>::clear(void) {
	size = 0;
}

generics
void gsArrayList<T>::log(void) { 
	if (size == 0) {
		GS_LOG("Lista vazia");
		return;
	}

	GS_LOG("Logging a lista inteira: ");
	for (int i = 0; i < size; i++)
	{
		GS_LOG(i << ": " << data[i]);
	}
}


#undef chunkSize
#undef generics
#endif