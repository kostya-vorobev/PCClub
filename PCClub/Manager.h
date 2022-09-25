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

	int GetIDManager();

	char* GetFIOManager();

	char* GetAdress();

	int GetSalary();

	void SetIDManager(int id);

	void SetFIOManager(char fio[]);

	void SetAdress(char Adress[]);

	void SetSalary(int Salary);

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


