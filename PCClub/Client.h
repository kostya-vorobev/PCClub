#pragma once
#include "lib.h"

struct Client
{
	int clientId;
	char fio[M/2];
};

void FprintfClient(Client dataInFileClient, const char* fileName, const char* endString);

Client ScanfClient();

Client FscanfClient(FILE* f);

void PrintfClient(Client objClient);

Client SearchClient();

void PrintfFromFileClient(const char* s);

void InitClient(Client* initClient, int id, const char* fio);

Client InitClient(int id, const char* fio);

int SearchClient(Client Original, const char* find);

void PrintfTitleClient();