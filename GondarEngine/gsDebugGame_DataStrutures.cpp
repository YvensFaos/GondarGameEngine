#include "gsDebugGame_DataStrutures.h"

#ifdef GS_DEBUG

#include "gsLogger.h"
#include "gsMacros.h"
#include "gsLinkedList.h"
#include "gsArrayList.h"
#include "gsHashMap.h"

void gsDebugGame_DataStrutures::start() {
	GS_LOG("Começando Testes");

	GS_LOG("\nTestando linked list: ");
	testLinkedList();

	GS_LOG("\nTestando array list: ");
	testArrayList();
	
	GS_LOG("\nTestando hash map: ");
	testHashMap();
}
void gsDebugGame_DataStrutures::end() {
	GS_LOG("Testes finalizados com sucesso.");
}

bool gsDebugGame_DataStrutures::isRunning() {
	return false;
}

void gsDebugGame_DataStrutures::update() {
	// Nada
}
void gsDebugGame_DataStrutures::draw() {
	// Nada
}


void gsDebugGame_DataStrutures::testLinkedList() {
	////gsLinkedList<float> list = gsLinkedList<float>();

	//gsLinkedList<float> list = gsLinkedList<float>();

	//// testando log de lista vazia
	//list.log();

	//// testando add
	//list.add(12.0f);
	//list.add(14.0f);
	//list.add(13.0f);

	//// testando log de lista ocupada
	//list.log();
	//
	//// testando contains
	//gsAssert(list.contains(13.0f));

	//// testando remove
	//list.remove(0);
	//list.log();
	//
	//// testando clear
	//list.clear();
	//list.log();

	//// testando resize
	//for (int i = 0; i < 60; i++)
	//{
	//	list.add((float)i);
	//}

	//list.log();
	//// testando o remove denovo
	//for (int i = 0; i < 50; i++)
	//{
	//	list.remove(0);
	//}
	//list.log();
}

void gsDebugGame_DataStrutures::testHashMap()
{
	gsHashMap<int> hash = gsHashMap<int>();

	hash.add(1, 111);

	hash.get(1);
	hash.remove(1);
	gsAssert(!hash.contains(2));

	hash.add(1, 111);
	hash.add(2, 222);
	hash.add(3, 333);

	hash.contains(2);
	hash.remove(2);
}

void gsDebugGame_DataStrutures::testArrayList() {
	gsArrayList<float> list = gsArrayList<float>();

	// testando log de lista vazia
	list.log();

	// testando add
	list.add(12.0f);
	list.add(14.0f);
	list.add(13.0f);

	// testando log de lista ocupada
	list.log();
	
	// testando contains
	gsAssert(list.contains(13.0f));

	// testando remove
	list.remove(0);
	list.log();
	
	// testando clear
	list.clear();
	list.log();

	// testando resize
	for (int i = 0; i < 60; i++)
	{
		list.add((float)i);
	}
	list.log();
	// testando o remove denovo
	for (int i = 0; i < 50; i++)
	{
		list.remove(0);
	}
	list.log();
}

#endif