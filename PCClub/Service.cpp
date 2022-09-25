#include "Service.h"

Service::Service(int id, const char* name, int tariff)
{
	this->servicesId = id;
	strcpy(this->name, name);
	this->tariff = tariff;
}

Service::Service()
{

}

Service::~Service()
{
}

void Service::CopyService(Service objService)
{
	this->servicesId = objService.servicesId;
	strcpy(this->name, objService.name);
	this->tariff = objService.tariff;
}

int Service::GetIDService()
{
	return this->servicesId;
}

char* Service::GetName()
{
	return this->name;
}

int Service::GetTariff()
{
	return this->tariff;
}

void Service::SetIDService(int ID)
{
	this->servicesId = ID;
}

void Service::SetName(char newName[])
{
	strcat(this->name, newName);
}

void Service::SetTariff(int newTariff)
{
	this->tariff = newTariff;
}

void Service::FprintfService(const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && this->servicesId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", this->servicesId);
		ReplaceCharacter(&this->name[0], ' ', '_');
		fprintf(f, "%s |", this->name);
		fprintf(f, "%d%s", this->tariff, endString);
		fclose(f);
	}
}

void Service::ScanfService() {


	this->servicesId = CountFillFile("Service.txt");
	do {
		InputString(this->name, "Введите название услуги: ", 49);
	} while (!IsWord(this->name));
	ReplaceCharacter(&this->name[0], ' ', '_');
	do {
		this->tariff = Get_int("Введите тариф услуги: ");
	} while (this->tariff <= 1);
}

void Service::FscanfService(FILE* f)
{
	fscanf(f, "%d |", &this->servicesId);
	fscanf(f, "%s |", this->name);
	ReplaceCharacter(&this->name[0], '_', ' ');
	fscanf(f, "%d\n", &this->tariff);
}

void Service::PrintfService()//вывод всех записей
{
	if (this->servicesId != 0) {
		printf("|%3d", this->servicesId);
		printf("|%25s", this->name);
		printf("|%10d|", this->tariff);
		printf("\n");
	}
	else {
		PrintfLine(42);
		printf("|%40s|\n", "Записей не найдено");
		PrintfLine(42);
	}
	return;
}

void Service::PrintfFromFileService(const char* s)
{
	FILE* f;
	Service objService{};
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleService();
			while (!feof(f)) {
				i++;
				this->FscanfService(f);
				this->PrintfService();
			}
			PrintfLine(42);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

void Service::SearchService()
{
	int searchId = 0;
	do {
		FILE* findInFile;
		findInFile = fopen("Service.txt", "r");
		searchId = Get_int("Введите id услуги: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			this->FscanfService(findInFile);
			if (this->servicesId == searchId)
			{
				return;
			}
		}
	} while (this->servicesId != searchId);
}

int Service::SearchService(const char* find)
{
	char ch[10];
	_itoa(this->servicesId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(this->name, find)) return 1;
	_itoa(this->tariff, ch, 10);
	if (strstr(ch, find)) return 1;
	return 0;

}

void Service::PrintfTitleService() {
	PrintfLine(42);
	printf("|%3s|%25s|%10s|\n", " № ", "Название", "Тариф");
	PrintfLine(42);
}

void Service::FscanfServiceOT(FILE* f)
{
	fscanf(f, "%d |", &this->servicesId);
	fscanf(f, "%s |", this->name);
	ReplaceCharacter(&this->name[0], '_', ' ');
	fscanf(f, "%d |", &this->tariff);
	return;
}

void Service::InitService(int id, const char* name, int tariff)
{
	this->servicesId = id;
	strcpy(this->name, name);
	this->tariff = tariff;
}