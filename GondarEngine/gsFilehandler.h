#ifndef __GS_FILE_HANDLER
#define __GS_FILE_HANDLER

#include <stdio.h>

class gsFileHandler
{
private:
	FILE* fileHandle;
	char* buffer;
	int bufSize;
	int bufLen;
	int bufPos;
	long fileSize;
	long filePos;
	char line[255];
	void readBuf();
	int readLn();

public:
	gsFileHandler(const char* fileName);
	~gsFileHandler();
	bool eof();
	char* readLnStr();
	int readLnInt();
	float readLnFloat();
	void close();
	int lineLen;
	int linesRead;
	int getLineLen();
	int getLinesRead();
};
#endif