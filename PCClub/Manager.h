#pragma once
#include "lib.h"

class Manager
{
private:
	int managerId;
	char fio[M / 2];
	char adress[M / 2];
	int salary;

public:
	Manager();

	Manager(int id, const char* fio, const char* adress, int salary);

	~Manager();

	void CopyManager(Manager objManager);

	int getIDManager();

	char* getFIOManager();

	char* getAdress();

	int getSalary();

	void setIDManager(int id);

	void setFIOManager(char fio[]);

	void setAdress(char Adress[]);

	void setSalary(int Salary);

	void FprintfManager(const char* fileName, const char* endString);

	Manager ScanfManager();

	Manager FileDataManager(FILE* f);

	Manager SearchManager();

	void PrintfManager();

	void PrintfFromFileManager(const char* s);

	void PrintfTitleManager();

	int SearchManager(const char* find);
	void FscanfManagerOT(FILE* f);
	void InitManager(int id, const char* fio, const char* adress, int salary);
};


