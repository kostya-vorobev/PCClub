#pragma once
#include "lib.h"
class Client
{


private:
	int clientId;
	char fio[M / 2];
public:

	Client();

	~Client();

	void CopyClient(Client objClient);

	int getIDClient();

	char* getFIOClient();

	void setIDClient(int ID);

	void setFIOClient(char fio[]);

	void FprintfClient(const char* fileName, const char* endString);

	Client ScanfClient();

	Client FileDataClient(FILE* f);

	void PrintfClient();

	Client SearchClient();

	void PrintfFromFileClient(const char* s);

	int SearchClient(const char* find);

	Client(int id, const char* fio);

	void PrintfTitleClient();

	void FscanfClientOT(FILE* f);
	void InitClient(int id, const char* fio);
};


