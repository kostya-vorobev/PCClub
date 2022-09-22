#pragma once
#include <stdio.h>

class Services
{
private:
	int servicesId;
	char name[50];
	int tariff;

public:
	Services(int newID, char newName[], int newTariff);
	Services(int newID);
	Services();
	~Services();

	int getID();

	char* getName();

	int getTariff();

	void setID(int ID);

	void setName(char newName[]);

	void setTariff(int newTariff);

	void writeFileServices(const char* fileName);

	void ServiceWriteUser();

	void outputServiceRecotrds();

	void ShowServiceDataFile(const char* s);

	void SearchService();

	void FileDataServiceDC(FILE* f);

	void FileDataService(FILE* f);
};

