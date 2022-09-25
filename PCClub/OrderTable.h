#pragma once
#include "lib.h"
#include "Manager.h"
#include "Client.h"
#include "PC.h"
#include "Service.h"

class OrderTable: public Manager, public Client, public PC, public Service
{
private:
	int orderTableId;
	char startTime[10];
	char finishTime[10];
	int cost;

public:
	OrderTable();

	OrderTable (int id, PC pcData, const char* startTime, const char* finishTime, Service servicesData, Client clientData, int cost, Manager managerData);

	~OrderTable();

	void FprintfOrderTable(const char* s);

	void PrintfOrderTable();

	void PrintfFromFileOrderTable(const char* s);

	OrderTable ScanfOrderTable();

	OrderTable FileOrderTable(FILE* f);

	void PrintfTitleOrderTable();

	int SearchOrderTable(const char* find);

	void InitOrderTable(int id, PC pcData, const char* startTime, const char* finishTime, Service servicesData, Client clientData, int cost, Manager managerData);

};


