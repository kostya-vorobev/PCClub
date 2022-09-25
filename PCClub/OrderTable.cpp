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

void OrderTable::FprintfOrderTable(const char* s)
{
	FILE* f;
	if (!IsFile(s)) {
		CreateFile(s);
	}
	if (IsFile(s) && this->orderTableId != 0) {
		f = fopen(s, "a");
		fprintf(f, "%d |", this->orderTableId);
		fprintf(f, "%d |", this->getIDPC());
		ReplaceCharacter(&this->getTypePC()[0], ' ', '_');
		fprintf(f, "%s |", this->getTypePC());
		fprintf(f, "%s |", this->startTime);
		fprintf(f, "%s |", this->finishTime);
		fprintf(f, "%d |", this->getIDService());
		ReplaceCharacter(&this->getName()[0], ' ', '_');
		fprintf(f, "%s |", this->getName());
		fprintf(f, "%d |", this->getTariff());
		fprintf(f, "%d |", this->getIDClient());
		ReplaceCharacter(&this->getFIOClient()[0], ' ', '_');
		fprintf(f, "%s |", this->getFIOClient());
		fprintf(f, "%d |", this->cost);
		fprintf(f, "%d |", this->getIDManager());
		ReplaceCharacter(&this->getFIOManager()[0], ' ', '_');
		fprintf(f, "%s |", this->getFIOManager());
		ReplaceCharacter(&this->getAdress()[0], ' ', '_');
		fprintf(f, "%s |", this->getAdress());
		fprintf(f, "%d\n", this->getSalary());
		fclose(f);
	}
}

void OrderTable::PrintfOrderTable()//����� ���� �������
{
	if (this->orderTableId != 0) {
		printf("|%3d", this->orderTableId);
		printf("|%25s", this->getFIOClient());
		printf("|%25s", this->getTypePC());
		printf("|%12s", this->startTime);
		printf("|%10s", this->finishTime);
		printf("|%10d", this->cost);
		printf("|%25s", this->getName());
		printf("|%25s|", this->getFIOManager());
		printf("\n");
	}
	else {
		PrintfLine(165);
		printf("|%163s|\n", "������� �� �������");
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
				this->FileOrderTable(f);
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
	InputString(this->startTime, "������� ����� ������ ������: ", 9);
	InputString(this->finishTime, "������� ����� ����� ������: ", 9);
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
	this->cost = get_int("������� ��������� ������: ");
	PrintfFromFileManager("Manager.txt");
	if (CountFillFile("Manager.txt") >= 1)
		this->SearchManager();
	else {
		this->ScanfManager();
		FprintfManager("Manager.txt", "\n");
	}
	return writingData;
}

OrderTable OrderTable::FileOrderTable(FILE* f)
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
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " � ", "��� �������", "��� ��", "����� ������", "����� �����", "���������", "������", "��� ���������");
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