#pragma once
#include "lib.h"

class Manager
{
private:
	int managerId;
	string fio;
	string adress;
	int salary;

public:



	Manager();

	Manager(int id, const string fio, const string adress, int salary);

	Manager(int id, const string fio, const string adress, int salary, int size);

	~Manager();

	void CopyManager(Manager objManager);

	int GetIDManager();

	int GetSizeStingManager();

	string GetFIOManager();

	string GetAdress();

	int GetSalary();

	void SetIDManager(int id);

	void SetFIOManager(string fio[]);

	void SetAdress(string Adress[]);

	void SetSalary(int Salary);

	void FprintfManager(const string fileName, const string endString);

	void ScanfManager();

	void FscanfManager(FILE* f);

	void SearchManager();

	void PrintfManager();

	void PrintfFromFileManager(const string s);

	void PrintfTitleManager();

	int SearchManager(const string find);

	void FscanfManagerOT(vector<string> words);

	void InitManager(int id, const string fio, const string adress, int salary);
};


