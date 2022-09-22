#include "lib.h"
#include "Services.h"

Services::Services(int newID, char newName[], int newTariff)
{
	this->servicesId = newID;
	this->tariff = newTariff;
	strcat(this->name, newName);
}
Services::Services(int newID)
{
	this->servicesId = newID;
}
Services::Services()
{
}

Services::~Services()
{
}

int Services::getID()
{
	return this->servicesId;
}

char* Services::getName()
{
	return this->name;
}

int Services::getTariff()
{
	return this->tariff;
}

void Services::setID(int ID)
{
	this->servicesId = ID;
}

void Services::setName(char newName[])
{
	strcat(this->name, newName);
}

void Services::setTariff(int newTariff)
{
	this->tariff = newTariff;
}

void Services::writeFileServices(const char* fileName)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && servicesId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", servicesId);
		replace(&name[0], ' ', '_');
		fprintf(f, "%s |", name);
		fprintf(f, "%d\n", tariff);
		fclose(f);
	}
}

void Services::ServiceWriteUser() {

	servicesId = CountFillFile("Service.txt");
	do {
		inputStringData(name, "Введите название услуги: ", 49);
	} while (!checkLect(name));
	replace(&name[0], ' ', '_');
	do {
		tariff = get_int("Введите тариф услуги: ");
	} while (tariff <= 1);
	return;
}

void Services::outputServiceRecotrds()//вывод всех записей
{
	if (servicesId != 0) {
		printf("|%3d", servicesId);
		printf("|%25s", name);
		printf("|%10d|", tariff);
		printf("\n");
	}
	else {
		outputLineRecotrds(42);
		printf("|%40s|\n", "Записей не найдено");
		outputLineRecotrds(42);
	}
	return;
}

void Services::ShowServiceDataFile(const char* s)
{
	FILE* f;
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitleServiceRecotrds();
			while (!feof(f)) {
				i++;
				FileDataService(f);
				outputServiceRecotrds();
			}
			outputLineRecotrds(42);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

void Services::SearchService()
{
	int searchId = 0;
	do {
		FILE* findInFile;
		findInFile = fopen("Service.txt", "r");
		searchId = get_int("Введите id услуги: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			FileDataService(findInFile);
			if (servicesId == searchId)
			{
				return;
			}
		}
	} while (servicesId != searchId);
};

void Services::FileDataServiceDC(FILE* f)
{
	fscanf(f, "%d |", &servicesId);
	fscanf(f, "%s |", name);
	replace(&name[0], '_', ' ');
	fscanf(f, "%d |", &tariff);
	return;
}

void Services::FileDataService(FILE* f)
{
	fscanf(f, "%d |", &servicesId);
	fscanf(f, "%s |", name);
	replace(&name[0], '_', ' ');
	fscanf(f, "%d\n", &tariff);
	return;
}