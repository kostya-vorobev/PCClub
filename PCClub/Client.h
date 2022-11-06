#pragma once
#include "IBase.h"

class Client: 
	public IBase
{

protected:
	int clientId;
	//string fio;
	int sizeLine;

public:

	Client();

	~Client();

	void CopyClient(Client objClient);

	int GetIDClient();

	string GetFio();

	void SetIDClient(int ID);

	void SetFio(string fio);

	void FprintfClient(const string fileName, const string endString);

	void ScanfClient();

	void FscanfClient(FILE* f);

	virtual void PrintfClient();

	void SearchClient();

	void PrintfFromFileClient(const string s);

	int SearchClient(const string find);

	Client(int id, const string fio);

	void PrintTitle();

	void FscanfClientOT(FILE* f);

	void InitClient(int id, const string fio);
};


