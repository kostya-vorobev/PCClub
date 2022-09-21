#pragma once
#include "Client.h"
#include "Manager.h"
#include "PC.h"
#include "Services.h"

class DataCenter : public PC, public Services, public Client, public Manager
{
private:
	int dataCenterId;
	//PC pcData;
	char rentalDataTime[10];
	char durationRentalDataTime[10];
	//Services servicesData{};
	//Client clientData{};
	int cost;
	//Manager managerData{};

public:
	DataCenter();
	~DataCenter();

	void writeFileDataCenter(const char* s);

	void FileDataCenter(FILE* f);

	void outputDataCenterRecotrds();

	void ShowDataCenterDataFile(const char* s);

	void DataCenterWriteUser();

};


