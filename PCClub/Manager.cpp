#include "Manager.h"
#include <iostream>

Manager::Manager(int id, const char* fio, const char* adress, int salary)
{
	this->managerId = id;
	strcpy(this->fio, fio);
	strcpy(this->adress, adress);
	this->salary = salary;
}

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::CopyManager(Manager objManager)
{
	this->managerId = objManager.managerId;
	strcpy(this->fio, objManager.fio);
	strcpy(this->adress, objManager.adress);
	this->salary = objManager.salary;
}

int Manager::GetIDManager()
{
	return this->managerId;
}

char* Manager::GetFIOManager()
{
	return this->fio;
}

char* Manager::GetAdress()
{
	return this->adress;
}

int Manager::GetSalary()
{
	return this->salary;
}

void Manager::SetIDManager(int id)
{
	this->managerId = id;
}

void Manager::SetFIOManager(char fio[])
{
	strcat(this->fio, fio);
}

void Manager::SetAdress(char Adress[])
{
	strcat(this->adress, Adress);
}
void Manager::SetSalary(int Salary)
{
	this->salary = Salary;
}

void Manager::FprintfManager(const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && this->managerId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", this->managerId);
		ReplaceCharacter(&this->fio[0], ' ', '_');
		fprintf(f, "%s |", this->fio);
		ReplaceCharacter(&this->adress[0], ' ', '_');
		fprintf(f, "%s |", this->adress);
		fprintf(f, "%d%s", this->salary, endString);
		fclose(f);
	}
}

void Manager::ScanfManager()
{
	this->managerId = CountFillFile("Manager.txt");
	do {
		InputString(this->fio, "Введите ФИО менеджера: ", 49);
	} while (!IsName(this->fio));
	ReplaceCharacter(&this->fio[0], ' ', '_');
	do {
		InputString(this->adress, "Введите адрес менеджера: ", 49);
	} while (!IsWord(this->adress));
	ReplaceCharacter(&this->adress[0], ' ', '_');
	do {
		this->salary = Get_int("Введите ставку мененджера: ");
	} while (this->salary <= 1);
}

void Manager::FscanfManager(FILE* f)
{
	fscanf(f, "%d |", &this->managerId);
	fscanf(f, "%s |", this->fio);
	ReplaceCharacter(&this->fio[0], '_', ' ');
	fscanf(f, "%s |", this->adress);
	ReplaceCharacter(&this->adress[0], '_', ' ');
	fscanf(f, "%d\n", &this->salary);
}

void Manager::SearchManager()
{
	int searchId = 0;
	do {
		FILE* findInFile;
		findInFile = fopen("Manager.txt", "r");
		searchId = Get_int("Введите id менеджера: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			this->FscanfManager(findInFile);
			if (this->managerId == searchId)
			{
				return;
			}
		}
	} while (this->managerId != searchId);
};

void Manager::PrintfManager()//вывод всех записей
{
	if (this->managerId != 0) {
		printf("|%3d", this->managerId);
		printf("|%25s", this->fio);
		printf("|%25s", this->adress);
		printf("|%10d|", this->salary);
		printf("\n");
	}
	else {
		PrintfLine(68);
		printf("|%66s|\n", "Записей не найдено");
		PrintfLine(68);
	}
	return;
}

void Manager::PrintfFromFileManager(const char* s)
{
	FILE* f;
	Manager objManager{};
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleManager();
			while (!feof(f)) {
				i++;
				this->FscanfManager(f);
				this->PrintfManager();
			}
			PrintfLine(68);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

void Manager::PrintfTitleManager() {
	PrintfLine(68);
	printf("|%3s|%25s|%25s|%10s|\n", " № ", "ФИО", "Адрес", "Ставка");
	PrintfLine(68);
}

int Manager::SearchManager(const char* find)
{
	char ch[10];
	_itoa(this->managerId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(this->fio, find)) return 1;
	if (strstr(this->adress, find)) return 1;
	_itoa(this->salary, ch, 10);
	if (strstr(ch, find)) return 1;
	return 0;
}

void Manager::FscanfManagerOT(FILE* f)
{
	fscanf(f, "%d |", &this->managerId);
	fscanf(f, "%s |", this->fio);
	ReplaceCharacter(&this->fio[0], '_', ' ');
	fscanf(f, "%s |", this->adress);
	ReplaceCharacter(&this->adress[0], '_', ' ');
	fscanf(f, "%d |", &this->salary);
	return;
}

void Manager::InitManager(int id, const char* fio, const char* adress, int salary)
{
	this->managerId = id;
	strcpy(this->fio, fio);
	strcpy(this->adress, adress);
	this->salary = salary;
}
