#include "gsDebugGame_DataStrutures.h"

#include "gsLogger.h"
#include "gsMacros.h"
#include "gsLinkedList.h"
#include "gsArrayList.h"


void gsDebugGame_DataStrutures::start() {
	GS_LOG("Come�ando Testes");

	GS_LOG("\nTestando linked list: ");
	testLinkedList();

	GS_LOG("\nTestando array list: ");
	testArrayList();
	
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
	//gsLinkedList<float> list = gsLinkedList<float>();

	gsLinkedList<float> list = gsLinkedList<float>();

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