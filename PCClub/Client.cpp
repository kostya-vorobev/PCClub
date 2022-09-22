#include "lib.h"
#include "Client.h"

Client::Client(int newID, char newFIO[])
{
	this->clientId = newID;
	strcat(this->FIO, newFIO);
}
Client::Client(int newID)
{
	this->clientId = newID;
}
Client::Client()
{
}

Client::~Client()
{
}

int Client::getID()
{
	return this->clientId;
}

char* Client::getFIO()
{
	return this->FIO;
}

void Client::setID(int ID)
{
	this->clientId = ID;
}

void Client::setFIO(char newFIO[])
{
	strcat(this->FIO, newFIO);
}

void Client::writeFileClient(const char* fileName)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && clientId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", clientId);
		replace(&FIO[0], ' ', '_');
		fprintf(f, "%s\n", FIO);
		fclose(f);
	}
}

void Client::ClientWriteUser()
{
	clientId = CountFillFile("Client.txt");
	do {
		inputStringData(FIO, "Введите ФИО клиента: ", 49);
	} while (!checkName(FIO));
	replace(&FIO[0], ' ', '_');
}

void Client::FileDataPCDC(FILE* f)
{
	fscanf(f, "%d |", &clientId);
	fscanf(f, "%s |", FIO);
	replace(&FIO[0], '_', ' ');
}

void Client::FileDataClientDC(FILE* f)
{
	fscanf(f, "%d |", &clientId);
	fscanf(f, "%s |", FIO);
	replace(&FIO[0], '_', ' ');
}

void Client::FileDataClient(FILE* f)
{
		fscanf(f, "%d |", &clientId);
		fscanf(f, "%s\n", FIO);
		replace(&FIO[0], '_', ' ');
}

void Client::outputClientRecotrds()//вывод всех записей
{
	if (clientId != 0) {
		printf("|%3d", clientId);
		printf("|%25s|", FIO);
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%30s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
	return;
}

void Client::ShowClientDataFile(const char* s)
{
	FILE* f;
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitleClientRecotrds();
			while (!feof(f)) {
				i++;
				FileDataClient(f);
				outputClientRecotrds();
			}
			outputLineRecotrds(32);
		}
		else outputNullSRecotrds();
		fclose(f);
	}
	_getch();
}

void Client::SearchClient()
{
	int searchId = 0;
	do {
		FILE* findInFile;
		findInFile = fopen("Client.txt", "r");
		searchId = get_int("Введите id клиента: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			FileDataClient(findInFile);
			if (clientId == searchId)
			{
				return;
			}
		}
	} while (clientId != searchId);
};