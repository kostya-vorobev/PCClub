#pragma once
#include "lib.h"
class Client
{


private:
	int clientId;
	string fio;
public:

	Client();

	~Client();

	void CopyClient(Client objClient);

	int GetIDClient();

	string GetFIOClient();

	void SetIDClient(int ID);

	void SetFIOClient(string fio[]);

	void FprintfClient(const string fileName, const string endString);

	void ScanfClient();

	void FscanfClient(FILE* f);

	void PrintfClient();

	void SearchClient();

	void PrintfFromFileClient(const string s);

	int SearchClient(const string find);

	Client(int id, const string fio);

	void PrintfTitleClient();

	void FscanfClientOT(FILE* f);
	void InitClient(int id, const string fio);
};


