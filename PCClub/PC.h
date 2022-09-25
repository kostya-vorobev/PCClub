#pragma once
#include "lib.h"

class PC
{
private:
	int PCId;
	char typePC[M / 2];

public:
	PC();

	PC(int id, const char* typePC);

	~PC();

	void CopyPC(PC objPC);

	int GetIDPC();

	char* GetTypePC();

	void SetIDPC(int ID);

	void SetTypePC(char newTypePC[]);

	void FprintfPC(const char* fileName, const char* endString);

	PC ScanfPC();

	PC FscanfPC(FILE* f);

	void PrintfPC();

	void PrintfFromFilePC(const char* s);

	PC SearchPC();

	int SearchPC(const char* find);

	void PrintfTitlePC();

	void FscanfPCOT(FILE* f);

	void InitPC(int id, const char* typePC);

};


