#include "OrderTable.h"

OrderTable::OrderTable()
{
}

OrderTable::OrderTable(int id, PC pcData, string startTime, string finishTime, Service servicesData, Client clientData, int cost, Manager managerData)
{
	this->orderTableId = id;
	this->CopyPC(pcData);
	this->startTime = startTime;
	this->finishTime = finishTime;
	this->CopyService(servicesData);
	this->CopyClient(clientData);
	this->cost = cost;
	this->CopyManager(managerData);
}

OrderTable::~OrderTable()
{
}

int OrderTable::GetIDOrderTable()
{
	return this->orderTableId;
}

string OrderTable::GetStartTime()
{
	return this->startTime;
}

string OrderTable::GetFinishTime()
{
	return this->finishTime;
}

int OrderTable::GetCost()
{
	return this->cost;
}

void OrderTable::SetIDOrderTable(int id)
{
	this->orderTableId = id;
}

void OrderTable::SetStartTime(const string time)
{
	this->startTime = time;
}

void OrderTable::SetFinishTime(string time)
{
	this->finishTime = time;
}

void OrderTable::SetCost(int cost)
{
	this->cost = cost;
}

void OrderTable::FprintfOrderTable(string fileName)
{
	FILE* f;
	if (!Lib::IsFile(fileName)) {
		Lib::CreateFile(fileName);
	}
	if (Lib::IsFile(fileName) && this->orderTableId != 0) {
		f = fopen(fileName.c_str(), "a");
		fprintf(f, "%d |", this->orderTableId);
		fprintf(f, "%d |", this->GetIDPC());
		GetTypePC().replace(GetTypePC().begin(), GetTypePC().end(), ' ', '_');
		fprintf(f, "%s |", this->GetTypePC().c_str());
		fprintf(f, "%s |", this->startTime.c_str());
		fprintf(f, "%s |", this->finishTime.c_str());
		fprintf(f, "%d |", this->GetIDService());
		GetName().replace(GetName().begin(), GetName().end(), ' ', '_');
		fprintf(f, "%s |", this->GetName().c_str());
		fprintf(f, "%d |", this->GetTariff());
		fprintf(f, "%d |", this->GetIDClient());
		GetFIOClient().replace(GetFIOClient().begin(), GetFIOClient().end(), ' ', '_');
		fprintf(f, "%s |", this->GetFIOClient().c_str());
		fprintf(f, "%d |", this->cost);
		fprintf(f, "%d |", this->GetIDManager());
		GetFIOManager().replace(GetFIOManager().begin(), GetFIOManager().end(), ' ', '_');
		fprintf(f, "%s |", this->GetFIOManager().c_str());
		GetAdress().replace(GetAdress().begin(), GetAdress().end(), ' ', '_');
		fprintf(f, "%s |", this->GetAdress().c_str());
		fprintf(f, "%d\n", this->GetSalary());
		fclose(f);
	}
}

void OrderTable::PrintfOrderTable()//вывод всех записей
{
	if (this->orderTableId != 0) {
		printf("|%3d", this->orderTableId);
		printf("|%25s", this->GetFIOClient().c_str());
		printf("|%25s", this->GetTypePC().c_str());
		printf("|%12s", this->startTime.c_str());
		printf("|%10s", this->finishTime.c_str());
		printf("|%10d", this->cost);
		printf("|%25s", this->GetName().c_str());
		printf("|%25s|", this->GetFIOManager().c_str());
		printf("\n");
	}
	else {
		Lib::PrintfLine(144);
		printf("|%142s|\n", "Записей не найдено");
		Lib::PrintfLine(144);
	}
	return;
}

void OrderTable::PrintfFromFileOrderTable(string fileName)
{
	FILE* f;
	int i = 0;
	if (Lib::IsFile(fileName)) {
		f = fopen(fileName.c_str(), "r");
		if (Lib::IsFillFile(fileName)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleOrderTable();
			while (!feof(f)) {
				i++;
				this->FscanfOrderTable(f);
				this->PrintfOrderTable();
			}
			Lib::PrintfLine(144);
		}
		else Lib::PrintfNullS();
		fclose(f);
	}
	_getch();
}

OrderTable OrderTable::ScanfOrderTable() {

	OrderTable writingData;
	this->orderTableId = Lib::CountFillFile("OrderTable.txt");
	PrintfFromFilePC("PC.txt");
	if (Lib::CountFillFile("PC.txt") >= 1)
		this->SearchPC();
	else {
		this->ScanfPC();
		FprintfPC("PC.txt", "\n");
	}
	const time_t timer = time(NULL);
	Lib::InputString(&this->startTime, "Введите время начала аренды: ");
	Lib::InputString(&this->finishTime, "Введите время конца аренды: ");
	PrintfFromFileService("Service.txt");
	if (Lib::CountFillFile("Service.txt") >= 1)
		this->SearchService();
	else {
		this->ScanfService();
		FprintfService("Service.txt", "\n");
	}
	PrintfFromFileClient("Client.txt");
	if (Lib::CountFillFile("Client.txt") >= 1)
		this->SearchClient();
	else {
		this->ScanfClient();
		FprintfClient("Client.txt", "\n");
	}
	this->cost = Lib::Get_int("Введите стоимость аренды: ");
	PrintfFromFileManager("Manager.txt");
	if (Lib::CountFillFile("Manager.txt") >= 1)
		this->SearchManager();
	else {
		this->ScanfManager();
		FprintfManager("Manager.txt", "\n");
	}
	return writingData;
}

void OrderTable::FscanfOrderTable(FILE* f)
{

	fscanf(f, "%d |", &this->orderTableId);
	this->FscanfPCOT(f);
	fscanf(f, "%s |", this->startTime.c_str());
	fscanf(f, "%s |", this->finishTime.c_str());
	this->FscanfServiceOT(f);
	this->FscanfClientOT(f);
	fscanf(f, "%d |", &this->cost);
	this->FscanfManagerOT(f);
}

void OrderTable::PrintfTitleOrderTable() {
	Lib::PrintfLine(144);
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " № ", "ФИО клиента", "Тип ПК", "Начало", "Конец", "Стоимость", "Услуга", "ФИО менеджера");
	Lib::PrintfLine(144);
}

int OrderTable::SearchOrderTable(const string find)
{
	string ch;
	ch = to_string(this->orderTableId);
	if (ch.find(find)) return 1;
	if (this->SearchPC(find)) return 1;
	if (this->startTime.find(find)) return 1;
	if (this->finishTime.find(find)) return 1;
	if (this->SearchService(find)) return 1;
	if (this->SearchClient(find)) return 1;
	ch = to_string(this->cost);
	if (ch.find(find)) return 1;
	if (this->SearchManager(find)) return 1;
	return 0;
}


void OrderTable::InitOrderTable(int id, PC pcData, const string startTime, const string finishTime, Service servicesData, Client clientData, int cost, Manager managerData)
{
	this->orderTableId = id;
	this->CopyPC(pcData);
	this->startTime = startTime;
	this->finishTime = finishTime;
	this->CopyService(servicesData);
	this->CopyClient(clientData);
	this->cost = cost;
	this->CopyManager(managerData);
}
