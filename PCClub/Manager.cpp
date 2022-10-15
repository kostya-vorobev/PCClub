#include "Manager.h"
#include <iostream>

Manager::Manager(int id, const string fio, const string adress, int salary)
{
	this->managerId = id;
	this->fio = fio;
	this->adress = adress;
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
	this->fio = objManager.fio;
	this->adress = objManager.adress;
	this->salary = objManager.salary;
}

int Manager::GetIDManager()
{
	return this->managerId;
}

string Manager::GetFIOManager()
{
	return this->fio;
}

string Manager::GetAdress()
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

void Manager::SetFIOManager(string fio[])
{
	this->fio += fio->c_str();
}

void Manager::SetAdress(string Adress[])
{
	this->adress += Adress->c_str();
}
void Manager::SetSalary(int Salary)
{
	this->salary = Salary;
}

void Manager::FprintfManager(const string fileName, const string endString)
{
	this->ScanfManager();
	FILE* f;
	if (!Lib::IsFile(fileName)) {
		Lib::CreateFile(fileName);
	}
	if (Lib::IsFile(fileName) && this->managerId != 0) {
		f = fopen(fileName.c_str(), "a");
		fprintf(f, "%d |", this->managerId);
		replace(fio.begin(), fio.end(), ' ', '_');
		fprintf(f, "%s |", this->fio.c_str());
		replace(adress.begin(), adress.end(), ' ', '_');
		fprintf(f, "%s |", this->adress.c_str());
		fprintf(f, "%d%s", this->salary, endString.c_str());
		fclose(f);
	}
}

void Manager::ScanfManager()
{
	this->managerId = Lib::CountFillFile("Manager.txt");
	do {
		Lib::InputString(&this->fio, "Введите ФИО менеджера: ", 49);
	} while (!Lib::IsName(this->fio));
	replace(fio.begin(), fio.end(), ' ', '_');
	do {
		Lib::InputString(&this->adress, "Введите адрес менеджера: ", 49);
	} while (!Lib::IsWord(this->adress));
	replace(adress.begin(), adress.end(), ' ', '_');
	do {
		this->salary = Lib::Get_int("Введите ставку мененджера: ");
	} while (this->salary <= 1);
}

void Manager::FscanfManager(FILE* f)
{
	fscanf(f, "%d |", &this->managerId);
	fscanf(f, "%s |", this->fio.c_str());
	this->fio = this->fio.c_str();
	replace(fio.begin(), fio.end(), '_', ' ');
	fscanf(f, "%s |", this->adress.c_str());
	this->adress = this->adress.c_str();
	replace(adress.begin(), adress.end(), '_', ' ');
	fscanf(f, "%d\n", &this->salary);
}

void Manager::SearchManager()
{
	int searchId = 0;
	do {
		FILE* findInFile;
		findInFile = fopen("Manager.txt", "r");
		searchId = Lib::Get_int("Введите id менеджера: ");
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
		printf("|%25s", this->fio.c_str());
		printf("|%25s", this->adress.c_str());
		printf("|%10d|", this->salary);
		printf("\n");
	}
	else {
		Lib::PrintfLine(68);
		printf("|%66s|\n", "Записей не найдено");
		Lib::PrintfLine(68);
	}
	return;
}

void Manager::PrintfFromFileManager(const string fileName)
{
	FILE* f;
	Manager objManager{};
	int i = 0;
	if (Lib::IsFile(fileName)) {
		f = fopen(fileName.c_str(), "r");
		if (Lib::IsFillFile(fileName)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleManager();
			while (!feof(f)) {
				i++;
				this->FscanfManager(f);
				this->PrintfManager();
			}
			Lib::PrintfLine(68);
		}
		else Lib::PrintfNullS();
		fclose(f);
	}
	_getch();
}

void Manager::PrintfTitleManager() {
	Lib::PrintfLine(68);
	printf("|%3s|%25s|%25s|%10s|\n", " № ", "ФИО", "Адрес", "Ставка");
	Lib::PrintfLine(68);
}

int Manager::SearchManager(const string find)
{
	string ch;
	ch = to_string(this->managerId);
	if (ch.find(find)) return 1;
	if (this->fio.find(find)) return 1;
	if (this->adress.find(find)) return 1;
	ch = to_string(this->salary);
	if (ch.find(find)) return 1;
	return 0;
}

void Manager::FscanfManagerOT(FILE* f)
{
	fscanf(f, "%d |", &this->managerId);
	fscanf(f, "%s |", this->fio.c_str());
	this->fio = this->fio.c_str();
	replace(fio.begin(), fio.end(), '_', ' ');
	fscanf(f, "%s |", this->adress.c_str());
	this->adress = this->adress.c_str();
	replace(adress.begin(), adress.end(), '_', ' ');
	fscanf(f, "%d |", &this->salary);
	return;
}

void Manager::InitManager(int id, const string fio, const string adress, int salary)
{
	this->managerId = id;
	this->fio = fio;
	this->adress = adress;
	this->salary = salary;
}
