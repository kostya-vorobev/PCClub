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

	friend bool operator< (const Client& left, const Client& right);

	friend bool operator> (const Client& left, const Client& right);

	friend ostream& operator<< (ostream& out, const Client& client);

	Client operator=(const Client& objClient);

	void SetFio(string fio);

	friend void FscanfFile(vector<Client>* client, string fileName);

	void FprintfClient(const string fileName, const string endString);

	void ScanfClient();

	void FscanfClient(string fileLine);

	virtual void PrintfClient();

	void SearchClient();

	void PrintfFromFileClient(const string s);

	int SearchClient(const string find);

	int SearchClient(Client find);

	Client(int id, const string fio);

	void PrintTitle();

	void FscanfClientOT(vector<string> words);

	void InitClient(int id, const string fio);
};


