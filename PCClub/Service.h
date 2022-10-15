#pragma once
#include "lib.h"
class Service
{


private:
	int servicesId;
	string name;
	int tariff;

public:

	Service(int id, const string name, int tariff);

	Service();

	~Service();

	Service operator+(const Service& r);

	Service& operator++();

	const Service& operator++(int);

	void CopyService(Service objService);

	int GetIDService();

	string GetName();

	int GetTariff();

	void SetIDService(int ID);

	void SetName(string newName[]);

	void SetTariff(int newTariff);

	void FprintfService(const string fileName, const string endString);

	void ScanfService();

	void FscanfService(FILE* f);

	void PrintfService();

	void PrintfFromFileService(const string s);

	void SearchService();

	int SearchService(const string find);

	void PrintfTitleService();

	void FscanfServiceOT(FILE* f);

	void InitService(int id, const string name, int tariff);
};



