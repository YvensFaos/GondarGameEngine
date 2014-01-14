#ifndef __FILE_HANDLER
#define __FILE_HANDLER

#include <stdio.h>

class FileHandler
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
	FileHandler(const char* fileName);
	~FileHandler();
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