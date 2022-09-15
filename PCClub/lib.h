#pragma once
#include <time.h>
#include <cstdio>
#include <string.h>
#include <conio.h>
void CreateFileS(const char* s);

struct Manager
{
	int managerId;
	char FIO[50];
	char adress[50];
	double salary;
};

struct Client
{
	int clientId;
	char FIO[50];
};

struct Services
{
	int servicesId;
	char name[50];
	double tariff;
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
	struct tm* rentalDataTime;
	struct tm* durationRentalDataTime;
	Services servicesData;
	Client clientData;
	double cost;
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
		return 0;
	}
	fclose(f);
	return i - 1;
}

void writeFileManager(Manager dataInFileManager, const char* fileName, const char* endString)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && dataInFileManager.managerId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d/", dataInFileManager.managerId);
		fprintf(f, "%s/", dataInFileManager.FIO);
		fprintf(f, "%s/", dataInFileManager.adress);
		fprintf(f, "%f%s", dataInFileManager.salary, endString);
		fclose(f);
	}
}

void writeFileClient(Client dataInFileClient, const char* fileName, const char* endString)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && dataInFileClient.clientId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d/", dataInFileClient.clientId);
		fprintf(f, "%s/", dataInFileClient.FIO);
		fprintf(f, "%s%s", dataInFileClient.adress, endString);
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
		fprintf(f, "%d/", dataInFileServices.servicesId);
		fprintf(f, "%s/", dataInFileServices.name);
		fprintf(f, "%f%s", dataInFileServices.tariff, endString);
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
		fprintf(f, "%d/", dataInFilePC.PCId);
		fprintf(f, "%s%s", dataInFilePC.typePC, endString);
		fclose(f);
	}
}

void writeFileDataCenter(DataCenter dataInFileDataCenter, const char* s)
{
	FILE* f;
	if (!CheckFile(s)) { 
		CreateFileS(s);
	}
	if (CheckFile(s) && dataInFileDataCenter.dataCenterId != 0) {
		f = fopen(s, "a");
		fprintf(f, "%d/", dataInFileDataCenter.dataCenterId);
		writeFilePC(dataInFileDataCenter.pcData, "DataCenter.txt", "/");
		fprintf(f, "%s/", dataInFileDataCenter.rentalDataTime);
		fprintf(f, "%s/", dataInFileDataCenter.durationRentalDataTime);
		writeFileServices(dataInFileDataCenter.servicesData, "DataCenter.txt", "/");
		writeFileClient(dataInFileDataCenter.clientData, "DataCenter.txt", "/");
		fprintf(f, "%f/", dataInFileDataCenter.cost);
		writeFileManager(dataInFileDataCenter.managerData, "DataCenter.txt", "\n");
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

int CountFillFile(const char* s)
{
	FILE* f;
	f = fopen(s, "r");
	int i = 0;
	while (!feof(f))
	{
		fscanf(f, "%*[^\n]%*c");
		i++;
	}
	if (i <= 1) {
		//printf("Файл пустой");
		fclose(f);
		return 0;
	}
	fclose(f);
	return i - 1;
}

Manager ManagerWriteUser()
{
	Manager writingData;
	writingData.managerId = CountFillFile("Manager.txt");
	do{
	inputStringData(writingData.FIO, "Введите ФИО менеджера: ", 49);
	} while (!checkName(writingData.FIO));
	do {
		inputStringData(writingData.adress, "Введите адрес менеджера: ", 49);
	} while (!checkName(writingData.adress));
	do {
		writingData.salary = get_int("Введите ставку мененджера: ");
	} while (writingData.salary <= 1);
	return writingData;
}

PC PCWriteUser()
{
	PC writingData;
	writingData.PCId = CountFillFile("PC.txt");
	do {
		inputStringData(writingData.typePC, "Введите тип ПК: ", 49);
	} while (!checkName(writingData.typePC));
	return writingData;
}

Client ClientWriteUser()
{
	Client writingData;
	writingData.clientId = CountFillFile("Client.txt");
	do {
		inputStringData(writingData.FIO, "Введите ФИО клиента: ", 49);
	} while (!checkName(writingData.FIO));
	return writingData;
}

Services ServiceWriteUser() {

	Services writingData;
	writingData.servicesId = CountFillFile("Services.txt");
	do {
		inputStringData(writingData.name, "Введите название услуги: ", 49);
	} while (!checkName(writingData.name));
	do {
		writingData.tariff = get_int("Введите тариф услуги: ");
	} while (writingData.tariff <= 1);
	return writingData;
}

