#include "Client.h"


Client::Client(int id, const string fio)
{
	this->clientId = id;
	this->fio = fio;
	this->sizeLine = 31;
}

Client::Client()
{
	this->clientId = 0;
	this->fio = "";
	this->sizeLine = 31;
}

Client::~Client()
{
}

void Client::CopyClient(Client objClient)
{
	 this->clientId = objClient.clientId;
	 this->fio = objClient.fio;
}
/*
Client Client::operator=(const Client& objClient)
{
	this->clientId = objClient.clientId;
	this->fio = objClient.fio;
	return *this;
}
*/
int Client::GetIDClient()
{
	return this->clientId;
}

string Client::GetFio()
{
	return this->fio;
}

void Client::SetIDClient(int id)
{
	this->clientId = id;
}

void Client::SetFio(string fio)
{
	this->fio = fio;
}


void Client::FprintfClient(const string fileName, const string endString)
{
	ScanfClient();
	ofstream f("Client.txt", ios_base::app);
	if (!f.is_open()) {
		Lib::CreateFile(fileName);
	}
	if (Lib::IsFile(fileName) && this->clientId != 0) {
		f << this->clientId;
		f << " |";
		f << this->fio;
		f << endl;
	}
	f.close();
}

void Client::ScanfClient()
{
	try {
		this->clientId = Lib::CountFillFile("Client.txt");
		do {
			Lib::InputString(&this->fio, "Введите ФИО клиента: ");
		} while (!Lib::IsName(this->fio));
		replace(fio.begin(), fio.end(), ' ', '_');
	}
	catch (const string ex)
	{
		cout << ex;
		_getch();
	}

}

void Client::FscanfClient(FILE* f)
{
	fscanf(f, "%d |", &this->clientId);
	fscanf(f, "%s\n", this->fio.c_str());
	this->fio = this->fio.c_str();
	replace(fio.begin(), fio.end(), '_', ' ');
}

void Client::PrintfClient()//вывод всех записей
{
	if (this->clientId != 0) {
		cout << "|";
		cout.width(3);
		cout << left << this->clientId;
		cout << "|";
		cout.width(25);
		cout << left << this->fio;
		cout << "|" << endl;
	}
	else {
		Lib::PrintfLine(this->sizeLine);
		cout << "|";
		cout.width(30);
		cout << "Записей не найдено" << "|" << endl;
		Lib::PrintfLine(this->sizeLine);
	}
	return;
}

void Client::SearchClient()
{
	int searchId = 0;
	try {
		do {
			FILE* findInFile;
			findInFile = fopen("Client.txt", "r");
			searchId = Lib::Get_int("Введите id клиента: ");
			while (!feof(findInFile)) //Считывание во временный файл
			{
				this->FscanfClient(findInFile);
				if (this->clientId == searchId)
				{
					return;
				}
			}
		} while (this->clientId != searchId);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

}

void Client::PrintfFromFileClient(const string fileName)
{
	FILE* f;
	int i = 0;
	try {
		if (Lib::IsFile(fileName)) {
			f = fopen(fileName.c_str(), "r");
			if (Lib::IsFillFile(fileName)) {
				fseek(f, 0, SEEK_SET);
				PrintTitle();
				while (!feof(f)) {
					i++;
					this->FscanfClient(f);
					this->PrintfClient();
				}
				Lib::PrintfLine(32);
			}
			else Lib::PrintfNullS();
			fclose(f);
		}
		else throw "Файл не найден!";
	}
	catch (const string err)
	{
		cout << err;
	}
	_getch();
}

int Client::SearchClient(const string find)
{
	string ch;
	ch = to_string(this->clientId);
	if (ch.find(find)) return 1;
	if (this->fio.find(find)) return 1;
	return 0;
}

void Client::PrintTitle() {
	Lib::PrintfLine(32);
	map <string, int> title = { {"№",3 },
								{"ФИО", 25} };
	map <string, int>::iterator it;
	for (it = title.begin(); it != title.end(); it++)
	{
		cout << "|";
		cout.width(it->second);
		cout << left << it->first;

	}
	cout << "|" << endl;
	Lib::PrintfLine(32);
}

void Client::FscanfClientOT(FILE* f)
{
	fscanf(f, "%d |", &this->clientId);
	fscanf(f, "%s |", this->fio.c_str());
	this->fio = this->fio.c_str();
	replace(fio.begin(), fio.end(), '_', ' ');
	return;
}

void Client::InitClient(int id, const string fio)
{
	this->clientId = id;
	this->fio = fio;
}
