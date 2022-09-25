#include "Client.h"

Client::Client(int id, const char* fio)
{
	this->clientId = id;
	strcpy(this->fio, fio);
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
	 strcpy(this->fio, objClient.fio);
}

int Client::GetIDClient()
{
	return this->clientId;
}

char* Client::GetFIOClient()
{
	return this->fio;
}

void Client::SetIDClient(int id)
{
	this->clientId = id;
}

void Client::SetFIOClient(char fio[])
{
	strcat(this->fio, fio);
}


void Client::FprintfClient(const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && this->clientId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", this->clientId);
		ReplaceCharacter(&this->fio[0], ' ', '_');
		fprintf(f, "%s%s", this->fio, endString);
		fclose(f);
	}
}

Client Client::ScanfClient()
{
	Client writingData;
	writingData.clientId = CountFillFile("Client.txt");
	do {
		InputString(writingData.fio, "Введите ФИО клиента: ", 49);
	} while (!IsName(writingData.fio));
	ReplaceCharacter(&writingData.fio[0], ' ', '_');

	return writingData;
}

Client Client::FileDataClient(FILE* f)
{
	Client fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.clientId);
	fscanf(f, "%s\n", fileDataObj.fio);
	ReplaceCharacter(&fileDataObj.fio[0], '_', ' ');
	return fileDataObj;
}

void Client::PrintfClient()//вывод всех записей
{
	if (this->clientId != 0) {
		printf("|%3d", this->clientId);
		printf("|%25s|", this->fio);
		printf("\n");
	}
	else {
		PrintfLine(165);
		printf("|%163s|\n", "Записей не найдено");
		PrintfLine(165);
	}
	return;
}

Client Client::SearchClient()
{
	int searchId = 0;
	Client findClient;
	do {
		FILE* findInFile;
		findInFile = fopen("Client.txt", "r");
		searchId = Get_int("Введите id клиента: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findClient = FileDataClient(findInFile);
			if (findClient.clientId == searchId)
			{
				return findClient;
			}
		}
	} while (findClient.clientId != searchId);
};

void Client::PrintfFromFileClient(const char* s)
{
	FILE* f;
	Client objClient{};
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleClient();
			while (!feof(f)) {
				i++;
				this->FileDataClient(f);
				this->PrintfClient();
			}
			PrintfLine(165);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

int Client::SearchClient(const char* find)
{
	char ch[10];
	_itoa(this->clientId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(this->fio, find)) return 1;
	return 0;
}

void Client::PrintfTitleClient() {
	PrintfLine(165);
	printf("|%3s|%25s|\n", " № ", "ФИО");
	PrintfLine(165);
}

void Client::FscanfClientOT(FILE* f)
{
	fscanf(f, "%d |", &this->clientId);
	fscanf(f, "%s |", this->fio);
	ReplaceCharacter(&this->fio[0], '_', ' ');
	return;
}

void Client::InitClient(int id, const char* fio)
{
	this->clientId = id;
	strcpy(this->fio, fio);
}
