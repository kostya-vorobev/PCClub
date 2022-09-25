#pragma once
#include "lib.h"

struct Manager
{
	int managerId;
	char fio[M/2];
	char adress[M/2];
	int salary;
};

void FprintfManager(Manager dataInFileManager, const char* fileName, const char* endString);

Manager ScanfManager();

Manager FscanfManager(FILE* f);

Manager SearchManager();

void PrintfManager(Manager objManager);

void PrintfFromFileManager(const char* s);

bool checkStringInFile(char s[M / 2][M / 2]);

void InitManager(Manager *initManager, int id, const char* fio, const char *adress, int salary);

Manager InitManager(int id, const char* fio, const char* adress, int salary);

void PrintfTitleManager();

int SearchManager(Manager Original, const char* find);