#include "Client.h"

Client::Client(int id, const string fio)
{
	this->clientId = id;
	this->fio = fio;
}

Client::Client()
{
}

Client::~Client()
{
}

void Client::CopyClient(Client objClient)
{
	 this->clientId = objClient.clientId;
	 this->fio = objClient.fio;
}

int Client::GetIDClient()
{
	return this->clientId;
}

string Client::GetFIOClient()
{
	return this->fio;
}

void Client::SetIDClient(int id)
{
	this->clientId = id;
}

void Client::SetFIOClient(string fio[])
{
	this->fio += fio->c_str();
}


void Client::FprintfClient(const string fileName, const string endString)
{
	ScanfClient();
	FILE* f;
	if (!Lib::IsFile(fileName)) {
		Lib::CreateFile(fileName);
	}
	if (Lib::IsFile(fileName) && this->clientId != 0) {
		f = fopen(fileName.c_str(), "a");
		fprintf(f, "%d |", this->clientId);
		replace(fio.begin(), fio.end(), ' ', '_');
		fprintf(f, "%s%s", this->fio.c_str(), endString.c_str());
		fclose(f);
	}
}

void Client::ScanfClient()
{
	this->clientId = Lib::CountFillFile("Client.txt");
	do {
		Lib::InputString(&this->fio, "Введите ФИО клиента: ", 49);
	} while (!Lib::IsName(this->fio));
	replace(fio.begin(), fio.end(), ' ', '_');
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
		printf("|%3d", this->clientId);
		printf("|%25s|", this->fio.c_str());
		printf("\n");
	}
	else {
		Lib::PrintfLine(32);
		printf("|%30s|\n", "Записей не найдено");
		Lib::PrintfLine(32);
	}
	return;
}

void Client::SearchClient()
{
	int searchId = 0;
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
};

void Client::PrintfFromFileClient(const string fileName)
{
	FILE* f;
	Client objClient{};
	int i = 0;
	if (Lib::IsFile(fileName)) {
		f = fopen(fileName.c_str(), "r");
		if (Lib::IsFillFile(fileName)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleClient();
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

void Client::PrintfTitleClient() {
	Lib::PrintfLine(32);
	printf("|%3s|%25s|\n", " № ", "ФИО");
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
