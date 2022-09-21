#include "lib.h"
#include "Manager.h"


Manager::Manager()
{
}

Manager::~Manager()
{
}

int Manager::getID()
{
	return managerId;
}

char* Manager::getFIO()
{
	return FIO;
}

char* Manager::getAdress()
{
	return adress;
}

int Manager::getSalary()
{
	return salary;
}

void Manager::setID(int ID)
{
	this->managerId = ID;
}

void Manager::setFIO(char newFIO[])
{
	strcat(this->FIO, newFIO);
}

void Manager::setAdress(char newAdress[])
{
	strcat(this->adress, newAdress);
}
void Manager::setSalary(int newSalary)
{
	this->salary = newSalary;
}

void Manager::writeFileManager(const char* fileName)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && managerId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", managerId);
		replace(&FIO[0], ' ', '_');
		fprintf(f, "%s |", FIO);
		replace(&adress[0], ' ', '_');
		fprintf(f, "%s |", adress);
		fprintf(f, "%d\n", salary);
		fclose(f);
	}
}

void Manager::ManagerWriteUser()
{
	managerId = CountFillFile("Manager.txt");
	do {
		inputStringData(FIO, "Введите ФИО менеджера: ", 49);
	} while (!checkName(FIO));
	replace(&FIO[0], ' ', '_');
	do {
		inputStringData(adress, "Введите адрес менеджера: ", 49);
	} while (!checkLect(adress));
	replace(&adress[0], ' ', '_');
	do {
		salary = get_int("Введите ставку мененджера: ");
	} while (salary <= 1);
}

void Manager::FileDataManager(FILE* f)
{
	fscanf(f, "%d |", &managerId);
	fscanf(f, "%s |", FIO);
	replace(&FIO[0], '_', ' ');
	fscanf(f, "%s |", adress);
	replace(&adress[0], '_', ' ');
	fscanf(f, "%d\n", &salary);
}

void Manager::outputManagerRecotrds()//вывод всех записей
{
	if (managerId != 0) {
		printf("|%3d", managerId);
		printf("|%25s", FIO);
		printf("|%25s", adress);
		printf("|%10d|", salary);
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%163s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
}

void Manager::ShowManagerDataFile(const char* s)
{
	FILE* f;
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitleManagerRecotrds();
			while (!feof(f)) {
				i++;
				FileDataManager(f);
				outputManagerRecotrds();
			}
			outputLineRecotrds(165);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

void Manager::SearchManager()
{
	int searchId = 0;
	do {
		FILE* findInFile;
		findInFile = fopen("Manager.txt", "r");
		searchId = get_int("Введите id менеджера: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			FileDataManager(findInFile);
			if (managerId == searchId)
			{
				return;
			}
		}
	} while (managerId != searchId);
};

