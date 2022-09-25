#include "Client.h"

void FprintfClient(Client dataInFileClient, const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && dataInFileClient.clientId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", dataInFileClient.clientId);
		ReplaceCharacter(&dataInFileClient.fio[0], ' ', '_');
		fprintf(f, "%s%s", dataInFileClient.fio, endString);
		fclose(f);
	}
}

Client ScanfClient()
{
	Client writingData;
	writingData.clientId = CountFillFile("Client.txt");
	do {
		InputString(writingData.fio, "Введите ФИО клиента: ", 49);
	} while (!IsName(writingData.fio));
	ReplaceCharacter(&writingData.fio[0], ' ', '_');

	return writingData;
}

Client FileDataClient(FILE* f)
{
	Client fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.clientId);
	fscanf(f, "%s\n", fileDataObj.fio);
	ReplaceCharacter(&fileDataObj.fio[0], '_', ' ');
	return fileDataObj;
}

void PrintfClient(Client objClient)//вывод всех записей
{
	if (objClient.clientId != 0) {
		printf("|%3d", objClient.clientId);
		printf("|%25s|", objClient.fio);
		printf("\n");
	}
	else {
		PrintfLine(165);
		printf("|%163s|\n", "Записей не найдено");
		PrintfLine(165);
	}
	return;
}

Client SearchClient()
{
	int searchId = 0;
	Client findClient;
	do {
		FILE* findInFile;
		findInFile = fopen("Client.txt", "r");
		searchId = get_int("Введите id клиента: ");
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

void PrintfFromFileClient(const char* s)
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
				objClient = FileDataClient(f);
				PrintfClient(objClient);
			}
			PrintfLine(165);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

void InitClient(Client* initClient, int id, const char* fio)
{
	initClient->clientId = id;
	strcpy(initClient->fio, fio);
}

Client InitClient(int id, const char* fio)
{
	Client initClient;
	initClient.clientId = id;
	strcpy(initClient.fio, fio);
	return initClient;
}

int SearchClient(Client Original, const char* find)
{
	char ch[10];
	_itoa(Original.clientId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(Original.fio, find)) return 1;
	return 0;
}

void PrintfTitleClient() {
	PrintfLine(165);
	printf("|%3s|%25s|\n", " № ", "ФИО");
	PrintfLine(165);
}