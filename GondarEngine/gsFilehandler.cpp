#include "gsFilehandler.h"

#include <stdlib.h>
#include <string.h>

gsFileHandler::gsFileHandler(const char* fileName)
{
	//Cria as instâncias necessárias para a leitura do arquivo
	//rb -> read as binary file (?)

	//fileHandle = fopen_s(fileName, "rb");

	fopen_s(&fileHandle, fileName, "rb");
	fseek(fileHandle, 0, SEEK_END);
	fileSize = ftell(fileHandle);
	filePos = 0;
	fseek(fileHandle, filePos, SEEK_SET);
	//2^14
	bufSize = 16384;
	buffer = new char[bufSize];
	bufLen = 0;
	bufPos = 0;

	//Linha adicionada
	linesRead = 0;
}

gsFileHandler::~gsFileHandler()
{
	close();
	delete buffer;
}

void gsFileHandler::readBuf()
{
	bufLen = fread(buffer, 1, bufSize, fileHandle);
	bufPos = 0;
	filePos += bufLen;
}

bool gsFileHandler::eof()
{
	bool hasBuf = bufPos < bufLen;
	bool hasFile = filePos < fileSize;
	return !(hasBuf || hasFile);
}

void gsFileHandler::close()
{
	if (fileHandle)
	{
		fclose(fileHandle);
		fileHandle = 0;
	}
	fileSize = 0;
	filePos = 0;
	bufLen = 0;
	bufPos = 0;

	//Linha adicionada
	linesRead = 0;
}

int gsFileHandler::readLn()
{
	//Método para ler uma linha do arquivo e apontar para a linha seguinte
	lineLen = 0;
	bool cr = false;
	while (true)
	{
		char ch;
		READ_CHAR_FROM_BUFFER:
		if (bufPos < bufLen)
			ch = buffer[bufPos++];
		else if (filePos < fileSize)
		{
			readBuf();
			//Poderia ser substituído por um continue;
			goto READ_CHAR_FROM_BUFFER; //goto?!
		}
		else{
			break;
		}

		//ch == 0  = NUL	0	0	0	^@	Null character
		//ch == 26 = SUB	32	26	1a	^Z	Substitute
		//ch == 10 = LF	    12	10	a	^J	Line Feed
		if (ch == 0 || ch == 26 || ch == 10){
			break;
		}

		if (cr){
			break;
		}

		if (ch == 13){
			cr = true;
		}
		else{
			line[lineLen++] = ch;
		}
	}
	line[lineLen] = 0x0;
	if(line[0] == '#')
	{
		//Comentário, ignorar
		linesRead++;
		return readLn();
	}
	linesRead++;

	return lineLen;
}

char* gsFileHandler::readLnStr()
{
	readLn();
	return &line[0];
}

int gsFileHandler::readLnInt()
{
	readLn();
	return atoi(line);
}

float gsFileHandler::readLnFloat()
{
	readLn();
	return atof(line);
}