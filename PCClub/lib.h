#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h> 
#include <clocale>
#include <Windows.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#define m 100 // Длина массива для исходной строки
void CreateFileS(const char* s);
void replace(char* str, char findSymb, char rezSymb);

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

	void writeFileManager(const char* fileName)
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

	void ManagerWriteUser()
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

	void FileDataManager(FILE* f)
	{
		fscanf(f, "%d |", &managerId);
		fscanf(f, "%s |", FIO);
		replace(&FIO[0], '_', ' ');
		fscanf(f, "%s |", adress);
		replace(&adress[0], '_', ' ');
		fscanf(f, "%d\n", &salary);
	}

	void outputManagerRecotrds()//вывод всех записей
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

	void ShowManagerDataFile(const char* s)
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

	void SearchManager()
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

};

Manager::Manager()
{
}

Manager::~Manager()
{
} 


struct Client
{
	int clientId;
	char FIO[50];
};

struct Services
{
	int servicesId;
	char name[50];
	int tariff;
};

struct PC
{
	int PCId;
	char typePC[50];
};

struct DataCenter
{
	int dataCenterId;
	PC pcData;
	char rentalDataTime[10];
	char durationRentalDataTime[10];
	Services servicesData;
	Client clientData;
	int cost;
	Manager managerData;
};

void CreateFileS(const char* s) {
	FILE* f;
	int k = 0;
	char c;
	f = fopen(s, "w");
	if (f == NULL) {
		printf("Ошибка при создании файла");
	}
}

bool CheckFile(const char* s)
{
	FILE* f;
	f = fopen(s, "r");
	if (f == NULL) {
		return false;
	}
	fclose(f);
	return true;
}

bool IsRange(int value, int min, int max)
{
	if (value < min) return false;
	if (value > max) return false;
	return true;
}

bool CheckDate(int day, int month, int year)
{
	if (year < 0)
		return false;

	switch (month)
	{
	case 1:  
	case 3:  
	case 5:  
	case 7:  
	case 8:  
	case 10: 
	case 12: 
		return IsRange(day, 1, 31);
	case 2:
		if (year % 4 == 0)
			return IsRange(day, 1, 29);
		else
			return IsRange(day, 1, 28);
	case 4:  
	case 6:  
	case 9:  
	case 11: 
		return IsRange(day, 1, 30);
	default:
		return false;
	}
}

int CountFillFile(const char* s)
{
	if (CheckFile(s)) {
		FILE* f;
		f = fopen(s, "r");
		int i = 0;
		while (!feof(f))
		{
			fscanf(f, "%*[^\n]%*c");
			i++;
		}
		if (i <= 1) {
			fclose(f);
			return 1;
		}
		fclose(f);
		return i;
	} return 1;

}



void writeFileClient(Client dataInFileClient, const char* fileName, const char* endString)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && dataInFileClient.clientId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", dataInFileClient.clientId);
		replace(&dataInFileClient.FIO[0], ' ', '_');
		fprintf(f, "%s%s", dataInFileClient.FIO, endString);
		fclose(f);
	}
}

void writeFileServices(Services dataInFileServices, const char* fileName, const char* endString)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && dataInFileServices.servicesId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", dataInFileServices.servicesId);
		replace(&dataInFileServices.name[0], ' ', '_');		
		fprintf(f, "%s |", dataInFileServices.name);
		fprintf(f, "%d%s", dataInFileServices.tariff, endString);
		fclose(f);
	}
}

void writeFilePC(PC dataInFilePC, const char* fileName, const char* endString)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && dataInFilePC.PCId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", dataInFilePC.PCId);
		replace(&dataInFilePC.typePC[0], ' ', '_');
		fprintf(f, "%s%s", dataInFilePC.typePC, endString);
		fclose(f);
	}
}

void writeFileDataCenter(DataCenter dataInFileDataCenter, const char* s)
{
	DataCenter writingdataInFileDataCenter = dataInFileDataCenter;
	FILE* f;
	if (!CheckFile(s)) { 
		CreateFileS(s);
	}
	if (CheckFile(s) && writingdataInFileDataCenter.dataCenterId != 0) {
		f = fopen(s, "a");
		fprintf(f, "%d |", writingdataInFileDataCenter.dataCenterId);
		fprintf(f, "%d |", writingdataInFileDataCenter.pcData.PCId);
		replace(&writingdataInFileDataCenter.pcData.typePC[0], ' ', '_');
		fprintf(f, "%s |", writingdataInFileDataCenter.pcData.typePC);
		fprintf(f, "%s |", writingdataInFileDataCenter.rentalDataTime);
		fprintf(f, "%s |", writingdataInFileDataCenter.durationRentalDataTime);
		fprintf(f, "%d |", writingdataInFileDataCenter.servicesData.servicesId);
		replace(&writingdataInFileDataCenter.servicesData.name[0], ' ', '_');
		fprintf(f, "%s |", writingdataInFileDataCenter.servicesData.name);
		fprintf(f, "%d |", writingdataInFileDataCenter.servicesData.tariff);
		fprintf(f, "%d |", writingdataInFileDataCenter.clientData.clientId);
		replace(&writingdataInFileDataCenter.clientData.FIO[0], ' ', '_');
		fprintf(f, "%s |", writingdataInFileDataCenter.clientData.FIO);
		fprintf(f, "%d |", writingdataInFileDataCenter.cost);
		fprintf(f, "%d |", writingdataInFileDataCenter.managerData.managerId);
		replace(&writingdataInFileDataCenter.managerData.FIO[0], ' ', '_');
		fprintf(f, "%s |", writingdataInFileDataCenter.managerData.FIO);
		replace(&writingdataInFileDataCenter.managerData.adress[0], ' ', '_');
		fprintf(f, "%s |", writingdataInFileDataCenter.managerData.adress);
		fprintf(f, "%d\n", writingdataInFileDataCenter.managerData.salary);
		fclose(f);
	}
}

void trim(char* s)
{
	// удаляем пробелы и табы с начала строки:
	int i = 0, j;
	while ((s[i] == ' ') || (s[i] == '\t'))
	{
		i++;
	}
	if (i > 0)
	{
		for (j = 0; j < strlen(s); j++)
		{
			s[j] = s[j + i];
		}
		s[j] = '\0';
	}

	// удаляем пробелы и табы с конца строки:
	i = strlen(s) - 1;
	while ((s[i] == ' ') || (s[i] == '\t'))
	{
		i--;
	}
	if (i < (strlen(s) - 1))
	{
		s[i + 1] = '\0';
	}
}

void inputStringData(char* s, const char* msg, int size)//ввод записей
{
	do {
		printf("%s", msg);
		fseek(stdin, 0, SEEK_END);
		fgets(s, size, stdin);
		trim(s);
		s[strlen(s) - 1] = 0;
		if (strlen(s) < 2)
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
	} while (strlen(s) < 2);
	return;
}



//Проверка ввода ФИО
bool checkName(char* s) {
	int flag = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ') flag = 1;
		if (s[i] != '.' && s[i] != ' ')
			if (!(s[i] < 'А' || s[i] > 'Я')) {}
			else if ((s[i] < 'а' || s[i] > 'я')) {
				printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
				return false;
			}
	}
	if (flag == 0) return false;
	return true;
}

//Функция ввода числа
int get_int(const char* msg) {
	char answer[256]; // строка для чтения
	int n = -1; // итоговое целое число
	do {
		printf("%s", msg); // выводим приглашение ко вводу
		fgets(answer, sizeof(answer), stdin); // считываем строку
		trim(answer);
		// пока не будет считано число
		while (sscanf(answer, "%d", &n) != 1) {
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
			_getch();
			fseek(stdin, 0, SEEK_END);
			printf("%s", msg); // выводим приглашение ко вводу
			fgets(answer, sizeof(answer), stdin); // и заново считываем строку
		}
	} while (n < 0);
	return n; // возвращаем корректное целое число
}

bool checkLect(char* s) {
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != '.' && s[i] != ' ')
			if (!(s[i] < 'А' || s[i] > 'Я')) {}
			else if ((s[i] < 'а' || s[i] > 'я')) {
				printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
				return false;
			}
	}
	return true;
}



PC PCWriteUser()
{
	PC writingData;
	writingData.PCId = CountFillFile("PC.txt");
	do {
		inputStringData(writingData.typePC, "Введите тип ПК: ", 49);
	} while (!checkLect(writingData.typePC));
	replace(&writingData.typePC[0], ' ', '_');
	return writingData;
}

Client ClientWriteUser()
{
	Client writingData;
	writingData.clientId = CountFillFile("Client.txt");
	do {
		inputStringData(writingData.FIO, "Введите ФИО клиента: ", 49);
	} while (!checkName(writingData.FIO));
	replace(&writingData.FIO[0], ' ', '_');

	return writingData;
}

Services ServiceWriteUser() {

	Services writingData;
	writingData.servicesId = CountFillFile("Service.txt");
	do {
		inputStringData(writingData.name, "Введите название услуги: ", 49);
	} while (!checkLect(writingData.name));
	replace(&writingData.name[0], ' ', '_');
	do {
		writingData.tariff = get_int("Введите тариф услуги: ");
	} while (writingData.tariff <= 1);
	return writingData;
}
void replace(char *str, char findSymb, char rezSymb)
{
	int sizeM = strlen(str);
	for (int i = 0; i < sizeM; i++)
	{
		if (*str == findSymb) *str = rezSymb;
		*str++;
	}
}

Client FileDataClient(FILE* f)
{
	Client fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.clientId);
	fscanf(f, "%s\n", fileDataObj.FIO);
	replace(&fileDataObj.FIO[0], '_', ' ');
	return fileDataObj;
}

PC FileDataPC(FILE* f)
{
	PC fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.PCId);
	fscanf(f, "%s\n", fileDataObj.typePC);
	replace(&fileDataObj.typePC[0], '_', ' ');
	return fileDataObj;
}

Services FileDataService(FILE* f)
{
	Services fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.servicesId);
	fscanf(f, "%s |", fileDataObj.name);
	replace(&fileDataObj.name[0], '_', ' ');
	fscanf(f, "%d\n", &fileDataObj.tariff);
	return fileDataObj;
}

DataCenter FileDataCenter(FILE* f)
{
	DataCenter fileDataObj{};

	fscanf(f, "%d |", &fileDataObj.dataCenterId);
	fscanf(f, "%d |", &fileDataObj.pcData.PCId);
	fscanf(f, "%s |", fileDataObj.pcData.typePC);
	replace(&fileDataObj.pcData.typePC[0], '_', ' ');
	fscanf(f, "%s |", fileDataObj.rentalDataTime);
	fscanf(f, "%s |", fileDataObj.durationRentalDataTime);
	fscanf(f, "%d |", &fileDataObj.servicesData.servicesId);
	fscanf(f, "%s |", fileDataObj.servicesData.name);
	replace(&fileDataObj.servicesData.name[0], '_', ' ');
	fscanf(f, "%d |", &fileDataObj.servicesData.tariff);
	fscanf(f, "%d |", &fileDataObj.clientData.clientId);
	fscanf(f, "%s |", fileDataObj.clientData.FIO);
	replace(&fileDataObj.clientData.FIO[0], '_', ' ');
	fscanf(f, "%d |", &fileDataObj.cost);
	fscanf(f, "%d |", &fileDataObj.managerData.managerId);
	fscanf(f, "%s |", fileDataObj.managerData.FIO);
	replace(&fileDataObj.managerData.FIO[0], '_', ' ');
	fscanf(f, "%s |", fileDataObj.managerData.adress);
	replace(&fileDataObj.managerData.adress[0], '_', ' ');
	fscanf(f, "%d\n", &fileDataObj.managerData.salary);
	return fileDataObj;
}


bool CheckFillFile(const char* s)
{
	FILE* f;
	f = fopen(s, "r");
	int i = 0;
	while (!feof(f))
	{
		fscanf(f, "%*[^\n]%*c");
		i++;
	}
	if (i == 0) {
		//printf("Файл пустой\n");
		fclose(f);
		return false;
	}
	fclose(f);
	return true;
}

void outputLineRecotrds(int index) {
	for (int i = 0; i < index; i++)
		printf("-");
	printf("\n");
}

void outputTitleManagerRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%25s|%10s|\n", " № ", "ФИО", "Адрес", "Ставка");
	outputLineRecotrds(165);
}
void outputTitleClientRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|\n", " № ", "ФИО");
	outputLineRecotrds(165);
}
void outputTitleServiceRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%10s|\n", " № ", "Название", "Тариф");
	outputLineRecotrds(165);
}
void outputTitlePCRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|\n", " № ", "Платформа");
	outputLineRecotrds(165);
}
void outputTitleDataCenterRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " № ", "ФИО клиента", "Тип ПК", "Время взятия", "Время сдачи", "Стоимость", "Услуга", "ФИО менеджера");
	outputLineRecotrds(165);
}



void outputClientRecotrds(Client objClient)//вывод всех записей
{
	if (objClient.clientId != 0) {
		printf("|%3d", objClient.clientId);
		printf("|%25s|", objClient.FIO);
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%163s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
	return;
}

void outputPCRecotrds(PC objPC)//вывод всех записей
{
	if (objPC.PCId != 0) {
		printf("|%3d", objPC.PCId);
		printf("|%25s|", objPC.typePC);
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%163s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
	return;
}

void outputServiceRecotrds(Services objService)//вывод всех записей
{
	if (objService.servicesId != 0) {
		printf("|%3d", objService.servicesId);
		printf("|%25s", objService.name);
		printf("|%10d|", objService.tariff);
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%163s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
	return;
}

void outputDataCenterRecotrds(DataCenter objDataCenter)//вывод всех записей
{
	if (objDataCenter.dataCenterId != 0) {
		printf("|%3d", objDataCenter.dataCenterId);
		printf("|%25s", objDataCenter.clientData.FIO);
		printf("|%25s", objDataCenter.pcData.typePC);
		printf("|%12s", objDataCenter.rentalDataTime);
		printf("|%10s", objDataCenter.durationRentalDataTime);
		printf("|%10d", objDataCenter.cost);
		printf("|%25s", objDataCenter.servicesData.name);
		printf("|%25s", objDataCenter.managerData.FIO);
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%163s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
	return;
}
void outputNullSRecotrds() {
	outputLineRecotrds(165);
	//outputUPSRecotrds();
	outputLineRecotrds(165);
	printf("|%163s|\n", "Записей не найдено");
	outputLineRecotrds(165);
}



void ShowClientDataFile(const char* s)
{
	FILE* f;
	Client objClient{};
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitleClientRecotrds();
			while (!feof(f)) {
				i++;
				objClient = FileDataClient(f);
				outputClientRecotrds(objClient);
			}
			outputLineRecotrds(165);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

void ShowPCDataFile(const char* s)
{
	FILE* f;
	PC objPC{};
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitlePCRecotrds();
			while (!feof(f)) {
				i++;
				objPC = FileDataPC(f);
				outputPCRecotrds(objPC);
			}
			outputLineRecotrds(165);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

void ShowServiceDataFile(const char* s)
{
	FILE* f;
	Services objService{};
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitleServiceRecotrds();
			while (!feof(f)) {
				i++;
				objService = FileDataService(f);
				outputServiceRecotrds(objService);
			}
			outputLineRecotrds(165);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

void ShowDataCenterDataFile(const char* s)
{
	FILE* f;
	DataCenter objDataCenter{};
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitleDataCenterRecotrds();
			while (!feof(f)) {
				i++;
				objDataCenter = FileDataCenter(f);
				outputDataCenterRecotrds(objDataCenter);
			}
			outputLineRecotrds(165);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

bool checkStringInFile(char s[m / 2][m / 2]) {
	FILE* f;
	f = fopen("Manager.txt", "r");
	int flag = 0;
	Manager objManager{};
	CreateFileS("tempSearch.txt");
	while (!feof(f))
	{
		objManager = FileDataManager(f);
		int i = 0;
		for (i = 0; s[i][0] != NULL; i++) {
			if (strstr(objManager.FIO, s[i]))
				flag++;
			if (strstr(objManager.adress, s[i]))
				flag++;
		}
		if (flag >= i)
			writeFileManager(objManager, "tempSearch.txt", "\n");
		flag = 0;
	}
	fclose(f);
	ShowManagerDataFile("tempSearch.txt");
	return 0;
}

PC SearchPC()
{
	int searchId = 0;
	PC findPC;
	do {
		FILE* findInFile;
		findInFile = fopen("PC.txt", "r");
		searchId = get_int("Введите id нужного компьютера: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findPC = FileDataPC(findInFile);
			if (findPC.PCId == searchId)
			{
				return findPC;
			}
		}
	} while (findPC.PCId != searchId);
};

Services SearchService()
{
	int searchId = 0;
	Services findService;
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
};

Client SearchClient()
{
	int searchId = 0;
	Client findClient;
	do {
		FILE* findInFile;
		findInFile = fopen("Client.txt", "r");
		searchId = get_int("Введите id клиента: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findClient = FileDataClient(findInFile);
			if (findClient.clientId == searchId)
			{
				return findClient;
			}
		}
	} while (findClient.clientId != searchId);
};



DataCenter DataCenterWriteUser() {

	DataCenter writingData;
	writingData.dataCenterId = CountFillFile("DataCenter.txt");
	ShowPCDataFile("PC.txt");
	if (CountFillFile("PC.txt") >= 1)
		writingData.pcData = SearchPC();
	else {
		writingData.pcData = PCWriteUser();
		writeFilePC(writingData.pcData, "PC.txt", "\n");
	}
	const time_t timer = time(NULL);
	inputStringData(writingData.rentalDataTime, "Введите время начала аренды: ", 9);
	inputStringData(writingData.durationRentalDataTime, "Введите время конца аренды: ", 9);
	ShowServiceDataFile("Service.txt");
	if (CountFillFile("Service.txt") >= 1)
		writingData.servicesData = SearchService();
	else {
		writingData.servicesData = ServiceWriteUser();
		writeFileServices(writingData.servicesData, "Service.txt", "\n");
	}
	ShowClientDataFile("Client.txt");
	if (CountFillFile("Client.txt") >= 1)
		writingData.clientData = SearchClient();
	else {
		writingData.clientData = ClientWriteUser();
		writeFileClient(writingData.clientData, "Client.txt", "\n");
	}
	writingData.cost = get_int("Введите стоимость аренды: ");
	ShowManagerDataFile("Manager.txt");
	if (CountFillFile("Manager.txt") >= 1)
		writingData.managerData = SearchManager();
	else {
		writingData.managerData = ManagerWriteUser();
		writeFileManager(writingData.managerData, "Manager.txt", "\n");
	}
	return writingData;
}