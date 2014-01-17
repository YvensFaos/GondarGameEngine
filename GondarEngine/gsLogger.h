#ifndef __GS_LOGGER__
#define __GS_LOGGER__


#include <sstream>

// Subsistema responsável por postar mensagens no console. utilize o macro GS_LOG para postar
// uma mensagem.
// Ex: int a = 10; GS_LOG("O valor da variável a é: " << a << ", use o operador << como o + do java para concatenar coisas");
class gsLogger {
public:
	static void init();

	static void log(const std::stringstream& message);
};


#define GS_LOG(a) {       \
	std::stringstream ss; \
	ss << a;              \
	gsLogger::log(ss);    \
}

#endif