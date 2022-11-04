#include "Service.h"

Service::Service(int id, const string name, int tariff)
{
	this->servicesId = id;
	this->name = name;
	this->tariff = tariff;
}

Service::Service()
{
	this->servicesId = 0;
	this->name = "";
	this->tariff = 0;
}

Service::~Service()
{
}

Service Service::operator+(const Service& r)
{
	this->tariff += r.tariff;
	return *this;
}

Service& Service::operator++()
{
	this->tariff += 100;
	return *this;
}

const Service& Service::operator++(int)
{
	Service temp{ *this };
	this->tariff += 100;
	return temp;
}

void Service::operator=(const Service& objService)
{
	this->servicesId = objService.servicesId;
	this->name = objService.name;
	this->tariff = objService.tariff;
}

void Service::CopyService(Service objService)
{
	this->servicesId = objService.servicesId;
	this->name = objService.name;
	this->tariff = objService.tariff;
}



int* Service::GetIDService()
{
	return &this->servicesId;
}

string Service::GetName()
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

void Service::SetName(string newName)
{
	this->name = newName;
}

void Service::SetTariff(int newTariff)
{
	this->tariff = newTariff;
}

void Service::FprintfService(const string fileName, const string endString)
{
	ScanfService();
	FILE* f;
	if (!Lib::IsFile(fileName)) {
		Lib::CreateFile(fileName);
	}
	if (Lib::IsFile(fileName) && this->servicesId != 0) {
		f = fopen(fileName.c_str(), "a");
		fprintf(f, "%d |", this->servicesId);
		replace(name.begin(), name.end(), ' ', '_');
		fprintf(f, "%s |", this->name.c_str());
		fprintf(f, "%d%s", this->tariff, endString.c_str());
		fclose(f);
	}
}

void Service::ScanfService() {


	this->servicesId = Lib::CountFillFile("Service.txt");
	do {
		Lib::InputString(&this->name, "Введите название услуги: ");
	} while (!Lib::IsWord(this->name));
	replace(name.begin(), name.end(), ' ', '_');
	do {
		this->tariff = Lib::Get_int("Введите тариф услуги: ");
	} while (this->tariff <= 1);
}

void Service::FscanfService(FILE* f)
{
	fscanf(f, "%d |", &this->servicesId);
	fscanf(f, "%s |", this->name.c_str());
	this->name = this->name.c_str();
	replace(name.begin(), name.end(), '_', ' ');
	fscanf(f, "%d\n", &this->tariff);
}

void Service::PrintfService()//вывод всех записей
{
	if (this->servicesId != 0) {
		printf("|%3d", this->servicesId);
		printf("|%25s", this->name.c_str());
		printf("|%10d|", this->tariff);
		printf("\n");
	}
	else {
		Lib::PrintfLine(42);
		printf("|%40s|\n", "Записей не найдено");
		Lib::PrintfLine(42);
	}
	return;
}

void Service::PrintfFromFileService(const string fileName)
{
	FILE* f;
	Service objService{};
	int i = 0;
	if (Lib::IsFile(fileName)) {
		f = fopen(fileName.c_str(), "r");
		if (Lib::IsFillFile(fileName)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleService();
			while (!feof(f)) {
				i++;
				this->FscanfService(f);
				this->PrintfService();
			}
			Lib::PrintfLine(42);
		}
		else Lib::PrintfNullS();
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
		searchId = Lib::Get_int("Введите id услуги: ");
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

int Service::SearchService(const string find)
{
	string ch;
	ch = to_string(this->servicesId);
	if (ch.find(find)) return 1;
	if (this->name.find(find)) return 1;
	ch = to_string(this->tariff);
	if (ch.find(find)) return 1;
	return 0;

}

void Service::PrintfTitleService() {
	Lib::PrintfLine(42);
	printf("|%3s|%25s|%10s|\n", " № ", "Название", "Тариф");
	Lib::PrintfLine(42);
}

void Service::FscanfServiceOT(FILE* f)
{
	fscanf(f, "%d |", &this->servicesId);
	fscanf(f, "%s |", this->name.c_str());
	this->name = this->name.c_str();
	replace(name.begin(), name.end(), '_', ' ');
	fscanf(f, "%d |", &this->tariff);
	return;
}

void Service::InitService(int id, const string name, int tariff)
{
	this->servicesId = id;
	this->name = name;
	this->tariff = tariff;
}


