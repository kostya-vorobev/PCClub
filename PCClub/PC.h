#pragma once
#include "lib.h"

struct PC
{
	int PCId;
	char typePC[M/2];
};

void FprintfPC(PC dataInFilePC, const char* fileName, const char* endString);

PC ScanfPC();

PC FileDataPC(FILE* f);

void PrintfPC(PC objPC);

void PrintfFromFilePC(const char* s);

PC SearchPC();

void InitPC(PC* initPC, int id, const char* typePC);

PC InitPC(int id, const char* typePC);

int SearchPC(PC Original, const char* find);

void PrintfTitlePC();