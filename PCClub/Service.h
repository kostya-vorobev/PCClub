#pragma once
#include "lib.h"

struct Services
{
	int servicesId;
	char name[M/2];
	int tariff;
};

void FprintfServices(Services dataInFileServices, const char* fileName, const char* endString);

Services ScanfService();

Services FileDataService(FILE* f);

void PrintfService(Services objService);

void PrintfFromFileService(const char* s);

Services SearchService();

void InitServices(Services* initServices, int id, const char* name, int tariff);

Services InitServices(int id, const char* name, int tariff);

int SearchService(Services Original, const char* find);

void PrintfTitleService();
