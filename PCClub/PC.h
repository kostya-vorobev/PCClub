#pragma once
#include <stdio.h>


class PC
{
private:
	int PCId;
	char typePC[50];

public:
	PC(int newID, char newTypePC[]);
	PC(int newID);
	PC();
	~PC();

	int getID();

	char* getTypePC();

	void setID(int ID);

	void setTypePC(char newTypePC[]);

	void writeFilePC(const char* fileName);

	void PCWriteUser();

	void outputPCRecotrds();

	void ShowPCDataFile(const char* s);

	void SearchPC();

	void FileDataPC(FILE* f);

	void FileDataPCDC(FILE* f);

};

