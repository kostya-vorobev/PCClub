#pragma once
#include <stdio.h>

class Services
{
private:
	int servicesId;
	char name[50];
	int tariff;

public:
	Services();
	~Services();

	int getID();

	char* getName();

	int getTariff();

	void setID(int ID);

	void setID(char newName[]);

	void setTariff(int newTariff);

	void writeFileServices(const char* fileName);

	void ServiceWriteUser();

	void outputServiceRecotrds();

	void ShowServiceDataFile(const char* s);

	void SearchService();

	void FileDataService(FILE* f);
};

