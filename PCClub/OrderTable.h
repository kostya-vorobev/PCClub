#pragma once
#include "lib.h"
#include "Manager.h"
#include "Client.h"
#include "PC.h"
#include "Service.h"

class OrderTable : public Manager, public Client, public PC, public Service
{
private:
	int orderTableId;
	string startTime;
	string finishTime;
	int cost;

public:
	OrderTable();

	OrderTable(int id, PC pcData, string startTime, string finishTime, Service servicesData, Client clientData, int cost, Manager managerData);

	~OrderTable();

	int GetIDOrderTable();

	void operator=(Service& objService);

	string GetStartTime();

	string GetFinishTime();

	int GetCost();

	void SetIDOrderTable(int id);

	void SetStartTime(string time);

	void SetFinishTime(string time);

	void SetCost(int cost);

	void FprintfOrderTable(string fileName);

	void PrintfOrderTable();

	void PrintfFromFileOrderTable(string fileName);

	OrderTable ScanfOrderTable();

	void FscanfOrderTable(string fileLine);

	void PrintfTitleOrderTable();

	int SearchOrderTable(string find);

	void InitOrderTable(int id, PC pcData, const string startTime, const string finishTime, Service servicesData, Client clientData, int cost, Manager managerData);

};


