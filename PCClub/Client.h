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

	int GetIDClient();

	char* GetFIOClient();

	void SetIDClient(int ID);

	void SetFIOClient(char fio[]);

	void FprintfClient(const char* fileName, const char* endString);

	void ScanfClient();

	void FscanfClient(FILE* f);

	void PrintfClient();

	void SearchClient();

	void PrintfFromFileClient(const char* s);

	int SearchClient(const char* find);

	Client(int id, const char* fio);

	void PrintfTitleClient();

	void FscanfClientOT(FILE* f);
	void InitClient(int id, const char* fio);
};


