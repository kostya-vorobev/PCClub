#include "OrderTable.h"

void FprintfOrderTable(OrderTable dataInFileOrderTable, const char* s)
{
	OrderTable writingData = dataInFileOrderTable;
	FILE* f;
	if (!IsFile(s)) {
		CreateFile(s);
	}
	if (IsFile(s) && writingData.orderTableId != 0) {
		f = fopen(s, "a");
		fprintf(f, "%d |", writingData.orderTableId);
		fprintf(f, "%d |", writingData.pcData.PCId);
		ReplaceCharacter(&writingData.pcData.typePC[0], ' ', '_');
		fprintf(f, "%s |", writingData.pcData.typePC);
		fprintf(f, "%s |", writingData.startTime);
		fprintf(f, "%s |", writingData.finishTime);
		fprintf(f, "%d |", writingData.servicesData.servicesId);
		ReplaceCharacter(&writingData.servicesData.name[0], ' ', '_');
		fprintf(f, "%s |", writingData.servicesData.name);
		fprintf(f, "%d |", writingData.servicesData.tariff);
		fprintf(f, "%d |", writingData.clientData.clientId);
		ReplaceCharacter(&writingData.clientData.fio[0], ' ', '_');
		fprintf(f, "%s |", writingData.clientData.fio);
		fprintf(f, "%d |", writingData.cost);
		fprintf(f, "%d |", writingData.managerData.managerId);
		ReplaceCharacter(&writingData.managerData.fio[0], ' ', '_');
		fprintf(f, "%s |", writingData.managerData.fio);
		ReplaceCharacter(&writingData.managerData.adress[0], ' ', '_');
		fprintf(f, "%s |", writingData.managerData.adress);
		fprintf(f, "%d\n", writingData.managerData.salary);
		fclose(f);
	}
}

void PrintfOrderTable(OrderTable objOrderTable)//вывод всех записей
{
	if (objOrderTable.orderTableId != 0) {
		printf("|%3d", objOrderTable.orderTableId);
		printf("|%25s", objOrderTable.clientData.fio);
		printf("|%25s", objOrderTable.pcData.typePC);
		printf("|%12s", objOrderTable.startTime);
		printf("|%10s", objOrderTable.finishTime);
		printf("|%10d", objOrderTable.cost);
		printf("|%25s", objOrderTable.servicesData.name);
		printf("|%25s|", objOrderTable.managerData.fio);
		printf("\n");
	}
	else {
		PrintfLine(144);
		printf("|%142s|\n", "Записей не найдено");
		PrintfLine(144);
	}
	return;
}

void PrintfFromFileOrderTable(const char* s)
{
	FILE* f;
	OrderTable objOrderTable{};
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleOrderTable();
			while (!feof(f)) {
				i++;
				objOrderTable = FileOrderTable(f);
				PrintfOrderTable(objOrderTable);
			}
			PrintfLine(144);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

OrderTable ScanfOrderTable() {

	OrderTable writingData;
	writingData.orderTableId = CountFillFile("OrderTable.txt");
	PrintfFromFilePC("PC.txt");
	if (CountFillFile("PC.txt") >= 1)
		writingData.pcData = SearchPC();
	else {
		writingData.pcData = ScanfPC();
		FprintfPC(writingData.pcData, "PC.txt", "\n");
	}
	const time_t timer = time(NULL);
	InputString(writingData.startTime, "Введите время начала аренды: ", 9);
	InputString(writingData.finishTime, "Введите время конца аренды: ", 9);
	PrintfFromFileService("Service.txt");
	if (CountFillFile("Service.txt") >= 1)
		writingData.servicesData = SearchService();
	else {
		writingData.servicesData = ScanfService();
		FprintfServices(writingData.servicesData, "Service.txt", "\n");
	}
	PrintfFromFileClient("Client.txt");
	if (CountFillFile("Client.txt") >= 1)
		writingData.clientData = SearchClient();
	else {
		writingData.clientData = ScanfClient();
		FprintfClient(writingData.clientData, "Client.txt", "\n");
	}
	writingData.cost = get_int("Введите стоимость аренды: ");
	PrintfFromFileManager("Manager.txt");
	if (CountFillFile("Manager.txt") >= 1)
		writingData.managerData = SearchManager();
	else {
		writingData.managerData = ScanfManager();
		FprintfManager(writingData.managerData, "Manager.txt", "\n");
	}
	return writingData;
}

OrderTable FileOrderTable(FILE* f)
{
	OrderTable fileDataObj{};

	fscanf(f, "%d |", &fileDataObj.orderTableId);
	fscanf(f, "%d |", &fileDataObj.pcData.PCId);
	fscanf(f, "%s |", fileDataObj.pcData.typePC);
	ReplaceCharacter(&fileDataObj.pcData.typePC[0], '_', ' ');
	fscanf(f, "%s |", fileDataObj.startTime);
	fscanf(f, "%s |", fileDataObj.finishTime);
	fscanf(f, "%d |", &fileDataObj.servicesData.servicesId);
	fscanf(f, "%s |", fileDataObj.servicesData.name);
	ReplaceCharacter(&fileDataObj.servicesData.name[0], '_', ' ');
	fscanf(f, "%d |", &fileDataObj.servicesData.tariff);
	fscanf(f, "%d |", &fileDataObj.clientData.clientId);
	fscanf(f, "%s |", fileDataObj.clientData.fio);
	ReplaceCharacter(&fileDataObj.clientData.fio[0], '_', ' ');
	fscanf(f, "%d |", &fileDataObj.cost);
	fscanf(f, "%d |", &fileDataObj.managerData.managerId);
	fscanf(f, "%s |", fileDataObj.managerData.fio);
	ReplaceCharacter(&fileDataObj.managerData.fio[0], '_', ' ');
	fscanf(f, "%s |", fileDataObj.managerData.adress);
	ReplaceCharacter(&fileDataObj.managerData.adress[0], '_', ' ');
	fscanf(f, "%d\n", &fileDataObj.managerData.salary);
	return fileDataObj;
}

void InitOrderTable(OrderTable* initOrderTable, int id, PC pcData, const char* startTime, const char* finishTime, Services servicesData, Client clientData, int cost, Manager managerData)
{
	initOrderTable->orderTableId = id;
	initOrderTable->pcData = pcData;
	strcpy(initOrderTable->startTime, startTime);
	strcpy(initOrderTable->finishTime, finishTime);
	initOrderTable->servicesData = servicesData;
	initOrderTable->clientData = clientData;
	initOrderTable->cost = cost;
	initOrderTable->managerData = managerData;
}

OrderTable InitOrderTable(int id, PC pcData, const char* startTime, const char* finishTime, Services servicesData, Client clientData, int cost, Manager managerData)
{
	OrderTable initOrderTable;
	initOrderTable.orderTableId = id;
	initOrderTable.pcData = pcData;
	strcpy(initOrderTable.startTime, startTime);
	strcpy(initOrderTable.finishTime, finishTime);
	initOrderTable.servicesData = servicesData;
	initOrderTable.clientData = clientData;
	initOrderTable.cost = cost;
	initOrderTable.managerData = managerData;
	return initOrderTable;
}

void PrintfTitleOrderTable() {
	PrintfLine(144);
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " № ", "ФИО клиента", "Тип ПК", "Время взятия", "Время сдачи", "Стоимость", "Услуга", "ФИО менеджера");
	PrintfLine(144);
}

int SearchOrderTable(OrderTable Original, const char* find)
{
	char ch[10];
	_itoa(Original.orderTableId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (SearchPC(Original.pcData, find)) return 1;
	if (strstr(Original.startTime, find)) return 1;
	if (strstr(Original.finishTime, find)) return 1;
	if (SearchService(Original.servicesData, find)) return 1;
	if (SearchClient(Original.clientData, find)) return 1;
	_itoa(Original.cost, ch, 10);
	if (strstr(ch, find)) return 1;
	if (SearchManager(Original.managerData, find)) return 1;
	return 0;
}
