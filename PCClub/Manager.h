#pragma once
#include <stdio.h>

class Manager
{

private:
	int managerId;
	char FIO[50];
	char adress[50];
	int salary;

public:
	Manager();
	~Manager();

	int getID();

	char* getFIO();

	char* getAdress();

	int getSalary();

	void setID(int ID);

	void setFIO(char newFIO[]);

	void setAdress(char newAdress[]);

	void setSalary(int newSalary);

	void writeFileManager(const char* fileName);

	void ManagerWriteUser();

	void FileDataManager(FILE* f);

	void outputManagerRecotrds();

	void ShowManagerDataFile(const char* s);

	void SearchManager();

};
