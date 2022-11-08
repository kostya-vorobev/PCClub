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
	this->operator=(servicesData);
	//this->CopyService(servicesData);
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

void OrderTable::operator=(Service& objService)
{
	this->SetIDService(*objService.GetIDService());
	this->SetName(objService.GetName());
	this->SetTariff(objService.GetTariff());
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
		GetFio().replace(GetFio().begin(), GetFio().end(), ' ', '_');
		fprintf(f, "%s |", this->GetFio().c_str());
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

void OrderTable::PrintfOrderTable()//����� ���� �������
{
	if (this->orderTableId != 0) {
		printf("|%3d", this->orderTableId);
		printf("|%25s", this->GetFio().c_str());
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
		printf("|%142s|\n", "������� �� �������");
		Lib::PrintfLine(144);
	}
	return;
}

void OrderTable::PrintfFromFileOrderTable(string fileName)
{
	try {
		int i = 0;
		if (Lib::IsFile(fileName)) {
			ifstream fout("OrderTable.txt", ios::in);
			if (Lib::IsFillFile(fileName)) {
				fout.seekg(0, ios::beg);
				PrintfTitleOrderTable();
				string fileLine;
				while (getline(fout, fileLine)) {
					i++;
					this->FscanfOrderTable(fileLine);
					this->PrintfOrderTable();
				}
				Lib::PrintfLine(144);
			}
			else Lib::PrintfNullS();
			fout.close();
		}
	}
	catch (const exception& e)
	{
		cout << e.what();
	}
		_getch();
	
}

OrderTable OrderTable::ScanfOrderTable() {
	try {
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
		Lib::InputString(&this->startTime, "������� ����� ������ ������: ");
		Lib::InputString(&this->finishTime, "������� ����� ����� ������: ");
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
		this->cost = Lib::Get_int("������� ��������� ������: ");
		PrintfFromFileManager("Manager.txt");
		if (Lib::CountFillFile("Manager.txt") >= 1)
			this->SearchManager();
		else {
			this->ScanfManager();
			FprintfManager("Manager.txt", "\n");
		}
		return writingData;
	}
	catch (const string ex)
	{
		cout << ex;
		_getch();
	}
}

void OrderTable::FscanfOrderTable(string fileLine)
{
	istringstream split(fileLine);
	vector<string> words;
	char split_char = '|';
	for (string each; getline(split, each, split_char); words.push_back(each));
	if (words.size() != 15) throw exception("���� ��� ���������, ��������� ����� �������� �����������");
	trim(words[0]);
	this->orderTableId = atoi(words[0].c_str());
	this->FscanfPCOT(words);
	this->startTime = words[3];
	replace(startTime.begin(), startTime.end(), '_', ' ');
	this->finishTime = words[4];
	replace(finishTime.begin(), finishTime.end(), '_', ' ');
	this->FscanfServiceOT(words);
	this->FscanfClientOT(words);
	trim(words[10]);
	this->cost = atoi(words[10].c_str());
	this->FscanfManagerOT(words);
}

void OrderTable::PrintfTitleOrderTable() {
	Lib::PrintfLine(144);
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " � ", "��� �������", "��� ��", "������", "�����", "���������", "������", "��� ���������");
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
