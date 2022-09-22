#include "lib.h"
#include "DataCenter.h"


DataCenter::DataCenter()
{
}

DataCenter::~DataCenter()
{
}

void DataCenter::writeFileDataCenter(const char* s)
{
	FILE* f;
	if (!CheckFile(s)) {
		CreateFileS(s);
	}
	if (CheckFile(s) && dataCenterId != 0) {
		f = fopen(s, "a");
		fprintf(f, "%d |", dataCenterId);
		fprintf(f, "%d |", DataCenter::PC::getID());
		replace(&DataCenter::PC::getTypePC()[0], ' ', '_');
		fprintf(f, "%s |", DataCenter::PC::getTypePC());
		fprintf(f, "%s |", rentalDataTime);
		fprintf(f, "%s |", durationRentalDataTime);
		fprintf(f, "%d |", DataCenter::Services::getID());
		replace(&DataCenter::Services::getName()[0], ' ', '_');
		fprintf(f, "%s |", DataCenter::Services::getName());
		fprintf(f, "%d |", DataCenter::Services::getTariff());
		fprintf(f, "%d |", DataCenter::Client::getID());
		replace(&DataCenter::Client::getFIO()[0], ' ', '_');
		fprintf(f, "%s |", DataCenter::Client::getFIO());
		fprintf(f, "%d |", cost);
		fprintf(f, "%d |", DataCenter::Manager::getID());
		replace(&DataCenter::Manager::getFIO()[0], ' ', '_');
		fprintf(f, "%s |", DataCenter::Manager::getFIO());
		replace(&DataCenter::Manager::getAdress()[0], ' ', '_');
		fprintf(f, "%s |", DataCenter::Manager::getAdress());
		fprintf(f, "%d\n", DataCenter::Manager::getSalary());
		fclose(f);
	}
}


void DataCenter::FileDataCenter(FILE* f)
{
	fscanf(f, "%d |", &dataCenterId);
	this->PC::FileDataPCDC(f);
	fscanf(f, "%s |", rentalDataTime);
	fscanf(f, "%s |", durationRentalDataTime);
	this->FileDataServiceDC(f);
	this->FileDataClientDC(f);
	fscanf(f, "%d |", &cost);
	this->FileDataManager(f);
	return;
}

void DataCenter::outputDataCenterRecotrds()//вывод всех записей
{
	if (dataCenterId != 0) {
		printf("|%3d", dataCenterId);
		printf("|%25s", DataCenter::Client::getFIO());
		printf("|%25s", DataCenter::PC::getTypePC());
		printf("|%12s", rentalDataTime);
		printf("|%10s", durationRentalDataTime);
		printf("|%10d", cost);
		printf("|%25s", DataCenter::Services::getName());
		printf("|%25s|", DataCenter::Manager::getFIO());
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%143s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
	return;
}

void DataCenter::ShowDataCenterDataFile(const char* s)
{
	FILE* f;
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitleDataCenterRecotrds();
			while (!feof(f)) {
				i++;
				FileDataCenter(f);
				outputDataCenterRecotrds();
			}
			outputLineRecotrds(145);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

void DataCenter::DataCenterWriteUser() {

	dataCenterId = CountFillFile("DataCenter.txt");
	this->ShowPCDataFile("PC.txt");
	if (CountFillFile("PC.txt") >= 1)
		this->SearchPC();
	else {
		this->PCWriteUser();
		this->writeFilePC("PC.txt");
	}
	const time_t timer = time(NULL);
	inputStringData(rentalDataTime, "Введите время начала аренды: ", 9);
	inputStringData(durationRentalDataTime, "Введите время конца аренды: ", 9);
	this->ShowServiceDataFile("Service.txt");
	if (CountFillFile("Service.txt") >= 1)
		this->SearchService();
	else {
		this->ServiceWriteUser();
		this->writeFileServices("Service.txt");
	}
	this->ShowClientDataFile("Client.txt");
	if (CountFillFile("Client.txt") >= 1)
		this->SearchClient();
	else {
		this->ClientWriteUser();
		this->writeFileClient("Client.txt");
	}
	cost = get_int("Введите стоимость аренды: ");
	this->ShowManagerDataFile("Manager.txt");
	if (CountFillFile("Manager.txt") >= 1)
		this->SearchManager();
	else {
		this->ManagerWriteUser();
		this->writeFileManager("Manager.txt");
	}
}