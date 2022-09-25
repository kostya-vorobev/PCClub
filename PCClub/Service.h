#pragma once
#include "lib.h"
class Service
{


private:
	int servicesId;
	char name[M / 2];
	int tariff;

public:

	Service(int id, const char* name, int tariff);

	Service();

	~Service();

	void CopyService(Service objService);

	int getIDService();

	char* getName();

	int getTariff();

	void setIDService(int ID);

	void setName(char newName[]);

	void setTariff(int newTariff);

	void FprintfService(const char* fileName, const char* endString);

	Service ScanfService();

	Service FileDataService(FILE* f);

	void PrintfService();

	void PrintfFromFileService(const char* s);

	Service SearchService();

	int SearchService(const char* find);

	void PrintfTitleService();
	void FscanfServiceOT(FILE* f);
	void InitService(int id, const char* name, int tariff);
};



