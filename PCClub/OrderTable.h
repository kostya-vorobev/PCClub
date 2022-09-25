#pragma once
#include "lib.h"
#include "Manager.h"
#include "Client.h"
#include "PC.h"
#include "Service.h"


struct OrderTable
{
	int orderTableId;
	PC pcData;
	char startTime[10];
	char finishTime[10];
	Services servicesData;
	Client clientData;
	int cost;
	Manager managerData;
};

void FprintfOrderTable(OrderTable dataInFileOrderTable, const char* s);

void PrintfOrderTable(OrderTable objOrderTable);

void PrintfFromFileOrderTable(const char* s);

OrderTable ScanfOrderTable();

OrderTable FileOrderTable(FILE* f);

void InitOrderTable(OrderTable* initOrderTable, int id, PC pcData, const char* startTime, const char* finishTime, Services servicesData, Client clientData, int cost, Manager managerData);

OrderTable InitOrderTable(int id, PC pcData, const char* startTime, const char* finishTime, Services servicesData, Client clientData, int cost, Manager managerData);

void PrintfTitleOrderTable();

int SearchOrderTable(OrderTable Original, const char* find);