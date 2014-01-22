#ifndef __GS_KEYVALUE__
#define __GS_KEYVALUE__

#define generics template <class T>

generics
class gsKeyValue {
public:
	int key;
	T value;

	gsKeyValue<T>(void);
	gsKeyValue<T>(int key, T value);
	
};
generics
bool operator==(gsKeyValue<T> kv1, gsKeyValue<T> kv2);


generics
gsKeyValue<T>::gsKeyValue(void) {}

generics
gsKeyValue<T>::gsKeyValue(int key, T value) {
	this->key = key;
	this->value = value;
}

generics
bool operator==(gsKeyValue<T> kv1, gsKeyValue<T> kv2) { return kv1.key == kv2.key; }

#undef generics
#endif