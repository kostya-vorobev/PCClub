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

Manager Manager::ScanfManager()
{
	Manager writingData;
	writingData.managerId = CountFillFile("Manager.txt");
	do {
		InputString(writingData.fio, "Введите ФИО менеджера: ", 49);
	} while (!IsName(writingData.fio));
	ReplaceCharacter(&writingData.fio[0], ' ', '_');
	do {
		InputString(writingData.adress, "Введите адрес менеджера: ", 49);
	} while (!IsWord(writingData.adress));
	ReplaceCharacter(&writingData.adress[0], ' ', '_');
	do {
		writingData.salary = Get_int("Введите ставку мененджера: ");
	} while (writingData.salary <= 1);
	return writingData;
}

Manager Manager::FscanfManager(FILE* f)
{
	Manager fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.managerId);
	fscanf(f, "%s |", fileDataObj.fio);
	ReplaceCharacter(&fileDataObj.fio[0], '_', ' ');
	fscanf(f, "%s |", fileDataObj.adress);
	ReplaceCharacter(&fileDataObj.adress[0], '_', ' ');
	fscanf(f, "%d\n", &fileDataObj.salary);
	return fileDataObj;
}

Manager Manager::SearchManager()
{
	int searchId = 0;
	Manager findManager;
	do {
		FILE* findInFile;
		findInFile = fopen("Manager.txt", "r");
		searchId = Get_int("Введите id менеджера: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findManager = FscanfManager(findInFile);
			if (findManager.managerId == searchId)
			{
				return findManager;
			}
		}
	} while (findManager.managerId != searchId);
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
		PrintfLine(165);
		printf("|%163s|\n", "Записей не найдено");
		PrintfLine(165);
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
			PrintfLine(165);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

void Manager::PrintfTitleManager() {
	PrintfLine(165);
	printf("|%3s|%25s|%25s|%10s|\n", " № ", "ФИО", "Адрес", "Ставка");
	PrintfLine(165);
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
