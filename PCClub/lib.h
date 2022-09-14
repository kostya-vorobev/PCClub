#pragma once
#include <time.h>
#include <cstdio>

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
	char adress[50];
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