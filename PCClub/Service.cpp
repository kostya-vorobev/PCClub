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

int Service::getIDService()
{
	return this->servicesId;
}

char* Service::getName()
{
	return this->name;
}

int Service::getTariff()
{
	return this->tariff;
}

void Service::setIDService(int ID)
{
	this->servicesId = ID;
}

void Service::setName(char newName[])
{
	strcat(this->name, newName);
}

void Service::setTariff(int newTariff)
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

Service Service::ScanfService() {

	Service writingData;
	writingData.servicesId = CountFillFile("Service.txt");
	do {
		InputString(writingData.name, "Введите название услуги: ", 49);
	} while (!IsWord(writingData.name));
	ReplaceCharacter(&writingData.name[0], ' ', '_');
	do {
		writingData.tariff = get_int("Введите тариф услуги: ");
	} while (writingData.tariff <= 1);
	return writingData;
}

Service Service::FileDataService(FILE* f)
{
	Service fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.servicesId);
	fscanf(f, "%s |", fileDataObj.name);
	ReplaceCharacter(&fileDataObj.name[0], '_', ' ');
	fscanf(f, "%d\n", &fileDataObj.tariff);
	return fileDataObj;
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
		PrintfLine(165);
		printf("|%163s|\n", "Записей не найдено");
		PrintfLine(165);
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
				this->FileDataService(f);
				this->PrintfService();
			}
			PrintfLine(165);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

Service Service::SearchService()
{
	int searchId = 0;
	Service findService;
	do {
		FILE* findInFile;
		findInFile = fopen("Service.txt", "r");
		searchId = get_int("Введите id услуги: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findService = FileDataService(findInFile);
			if (findService.servicesId == searchId)
			{
				return findService;
			}
		}
	} while (findService.servicesId != searchId);
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
	PrintfLine(165);
	printf("|%3s|%25s|%10s|\n", " № ", "Название", "Тариф");
	PrintfLine(165);
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