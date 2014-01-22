#include "gsInput.h"

#include "gsWindow.h"
#include "gsArrayList.h"
#include "gsHashMap.h"

class gsKeyData {
public:
	int keyCode;
	bool last;
	bool current;
	bool next;

	gsKeyData() { 
		last = current = next = false; 
		keyCode = -1;
	}
	gsKeyData(int key) { 
		last = current = next = false; 
		keyCode = key;
	}

	void update() {
		last = current;
		current = next;
	}
};

gsArrayList<gsKeyData> gKeys;
gsHashMap<gsKeyData*> gKeysMapping;
int gOldCapacity;


void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_UNKNOWN) {
		return;
	}

	if (!gKeysMapping.contains(key)) {
		gsKeyData newKey(key);
		gKeys.add(newKey);
		gKeysMapping.add(key, gKeys.getAddress(gKeys.getSize() - 1));

		if (gKeys.getCapacity() != gOldCapacity) {
			gKeysMapping.clear();

			for (int i = 0; i < gKeys.getSize(); i++)
			{
				gsKeyData *keyData = gKeys.getAddress(i);
				gKeysMapping.add(keyData->keyCode, keyData);
			}
			gOldCapacity = gKeys.getCapacity();
		}
	}

	if(action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		gKeysMapping.get(key)->next = true;
	} else if (action == GLFW_RELEASE) {
		gKeysMapping.get(key)->next = false;
	}
	
	
}

void gsInput::init() {
	glfwSetKeyCallback(gsWindow::getWindow(), glfwKeyCallback);
	gOldCapacity = gKeys.getCapacity();
}

void gsInput::update() {
	for (int i = 0; i < gKeys.getSize(); i++)
	{
		gKeys.getAddress(i)->update();
	}
}

gsKeyState gsInput::queryKey(int keyCode) {
	if (!gKeysMapping.contains(keyCode)) {
		return gsKeyState::Released; // Essa tecla nunca foi apertada.
	}

	gsKeyData *keyData = gKeysMapping.get(keyCode);
	if (keyData->current == true) {
		if (keyData->last == true) {
			return gsKeyState::Pressed;
		} else {
			return gsKeyState::JustPressed;
		}
	} else {
		if (keyData->last == true) {
			return gsKeyState::JustReleased;
		} else {
			return gsKeyState::Released;
		}
	}
}