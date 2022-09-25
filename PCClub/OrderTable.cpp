#include "OrderTable.h"

OrderTable::OrderTable()
{
}

OrderTable::OrderTable(int id, PC pcData, const char* startTime, const char* finishTime, Service servicesData, Client clientData, int cost, Manager managerData)
{
	this->orderTableId = id;
	this->CopyPC(pcData);
	strcpy(this->startTime, startTime);
	strcpy(this->finishTime, finishTime);
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

char* OrderTable::GetStartTime()
{
	return this->startTime;
}

char* OrderTable::GetFinishTime()
{
	return this->finishTime;
}

char OrderTable::GetCost()
{
	return this->cost;
}

void OrderTable::SetIDOrderTable(int id)
{
	this->orderTableId = id;
}

void OrderTable::SetStartTime(const char* time)
{
	strcpy(this->startTime, time);
}

void OrderTable::SetFinishTime(const char* time)
{
	strcpy(this->finishTime, time);
}

void OrderTable::SetCost(int cost)
{
	this->cost = cost;
}

void OrderTable::FprintfOrderTable(const char* s)
{
	FILE* f;
	if (!IsFile(s)) {
		CreateFile(s);
	}
	if (IsFile(s) && this->orderTableId != 0) {
		f = fopen(s, "a");
		fprintf(f, "%d |", this->orderTableId);
		fprintf(f, "%d |", this->GetIDPC());
		ReplaceCharacter(&this->GetTypePC()[0], ' ', '_');
		fprintf(f, "%s |", this->GetTypePC());
		fprintf(f, "%s |", this->startTime);
		fprintf(f, "%s |", this->finishTime);
		fprintf(f, "%d |", this->GetIDService());
		ReplaceCharacter(&this->GetName()[0], ' ', '_');
		fprintf(f, "%s |", this->GetName());
		fprintf(f, "%d |", this->GetTariff());
		fprintf(f, "%d |", this->GetIDClient());
		ReplaceCharacter(&this->GetFIOClient()[0], ' ', '_');
		fprintf(f, "%s |", this->GetFIOClient());
		fprintf(f, "%d |", this->cost);
		fprintf(f, "%d |", this->GetIDManager());
		ReplaceCharacter(&this->GetFIOManager()[0], ' ', '_');
		fprintf(f, "%s |", this->GetFIOManager());
		ReplaceCharacter(&this->GetAdress()[0], ' ', '_');
		fprintf(f, "%s |", this->GetAdress());
		fprintf(f, "%d\n", this->GetSalary());
		fclose(f);
	}
}

void OrderTable::PrintfOrderTable()//вывод всех записей
{
	if (this->orderTableId != 0) {
		printf("|%3d", this->orderTableId);
		printf("|%25s", this->GetFIOClient());
		printf("|%25s", this->GetTypePC());
		printf("|%12s", this->startTime);
		printf("|%10s", this->finishTime);
		printf("|%10d", this->cost);
		printf("|%25s", this->GetName());
		printf("|%25s|", this->GetFIOManager());
		printf("\n");
	}
	else {
		PrintfLine(165);
		printf("|%163s|\n", "Записей не найдено");
		PrintfLine(165);
	}
	return;
}

void OrderTable::PrintfFromFileOrderTable(const char* s)
{
	FILE* f;
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleOrderTable();
			while (!feof(f)) {
				i++;
				this->PrintfFromFileOrderTable(f);
				this->PrintfOrderTable();
			}
			PrintfLine(165);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

OrderTable OrderTable::ScanfOrderTable() {

	OrderTable writingData;
	this->orderTableId = CountFillFile("OrderTable.txt");
	PrintfFromFilePC("PC.txt");
	if (CountFillFile("PC.txt") >= 1)
		this->SearchPC();
	else {
		this->ScanfPC();
		FprintfPC("PC.txt", "\n");
	}
	const time_t timer = time(NULL);
	InputString(this->startTime, "Введите время начала аренды: ", 9);
	InputString(this->finishTime, "Введите время конца аренды: ", 9);
	PrintfFromFileService("Service.txt");
	if (CountFillFile("Service.txt") >= 1)
		this->SearchService();
	else {
		this->ScanfService();
		FprintfService("Service.txt", "\n");
	}
	PrintfFromFileClient("Client.txt");
	if (CountFillFile("Client.txt") >= 1)
		this->SearchClient();
	else {
		this->ScanfClient();
		FprintfClient("Client.txt", "\n");
	}
	this->cost = Get_int("Введите стоимость аренды: ");
	PrintfFromFileManager("Manager.txt");
	if (CountFillFile("Manager.txt") >= 1)
		this->SearchManager();
	else {
		this->ScanfManager();
		FprintfManager("Manager.txt", "\n");
	}
	return writingData;
}

OrderTable OrderTable::PrintfFromFileOrderTable(FILE* f)
{
	OrderTable fileDataObj{};

	fscanf(f, "%d |", &fileDataObj.orderTableId);
	fileDataObj.FscanfPCOT(f);
	fscanf(f, "%s |", fileDataObj.startTime);
	fscanf(f, "%s |", fileDataObj.finishTime);
	fileDataObj.FscanfServiceOT(f);
	fileDataObj.FscanfClientOT(f);
	fscanf(f, "%d |", &fileDataObj.cost);
	fileDataObj.FscanfManagerOT(f);
	return fileDataObj;
}

void OrderTable::PrintfTitleOrderTable() {
	PrintfLine(165);
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " № ", "ФИО клиента", "Тип ПК", "Время взятия", "Время сдачи", "Стоимость", "Услуга", "ФИО менеджера");
	PrintfLine(165);
}

int OrderTable::SearchOrderTable(const char* find)
{
	char ch[10];
	_itoa(this->orderTableId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (this->SearchPC(find)) return 1;
	if (strstr(this->startTime, find)) return 1;
	if (strstr(this->finishTime, find)) return 1;
	if (this->SearchService(find)) return 1;
	if (this->SearchClient(find)) return 1;
	_itoa(this->cost, ch, 10);
	if (strstr(ch, find)) return 1;
	if (this->SearchManager(find)) return 1;
	return 0;
}


void OrderTable::InitOrderTable(int id, PC pcData, const char* startTime, const char* finishTime, Service servicesData, Client clientData, int cost, Manager managerData)
{
	this->orderTableId = id;
	this->CopyPC(pcData);
	strcpy(this->startTime, startTime);
	strcpy(this->finishTime, finishTime);
	this->CopyService(servicesData);
	this->CopyClient(clientData);
	this->cost = cost;
	this->CopyManager(managerData);
}