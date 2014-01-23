#ifndef __GS_MACROS__
#define __GS_MACROS__

// Arquivo com alguns macros importantes
// Macros que começam com dois underlines não devem se utilizados fora de seus respectivos arquivos

// Macro para identificar se nós estamos em modo debug
#if defined(DEBUG) | defined (_DEBUG)
	#define GS_DEBUG
#else
	#define GS_RELEASE
#endif

#define __GS_STRINGIZING_OP(x) #x // Macro utilitário para o macro abaixo
// Converte o parâmetro "x" em um const char*
#define GS_STRINGIZE(x) __GS_STRINGIZING_OP(x)

// Macro para pegar o nome do arquivo e linha onde ele for chamado
#define GS_DEBUG_INFO "File: " __FILE__ ", Line: " GS_STRINGIZE(__LINE__)

// assert macro
#ifdef GS_DEBUG
	#include <Windows.h>
	#include <stdio.h>
	#define gsAssert(x) {                                                           \
		if (!(x)) {                                                                 \
			printf("Assertion error at: " GS_STRINGIZE(x) " at: " GS_DEBUG_INFO);   \
			DebugBreak();                                                           \
		}                                                                           \
	}
#else
	#define gsAssert(x)
#endif

#endif