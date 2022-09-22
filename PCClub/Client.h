#pragma once
#include <stdio.h>

class Client
{
private:
	int clientId;
	char FIO[50];

public:
	Client(int newID, char newFIO[]);
	Client(int newID);
	Client();
	~Client();

	int getID();

	char* getFIO();

	void setID(int);

	void setFIO(char newFIO[]);

	void writeFileClient(const char*);

	void ClientWriteUser();

	void FileDataPCDC(FILE* f);

	void FileDataClientDC(FILE* f);

	void FileDataClient(FILE* f);

	void outputClientRecotrds();

	void ShowClientDataFile(const char*);

	void SearchClient();

};

