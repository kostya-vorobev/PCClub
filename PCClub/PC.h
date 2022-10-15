#pragma once
#include "lib.h"

class PC
{
private:
	int PCId;
	string typePC;

public:
	PC();

	PC(int id, const string typePC);

	~PC();

	void CopyPC(PC objPC);

	int GetIDPC();

	string GetTypePC();

	void SetIDPC(int ID);

	void SetTypePC(string newTypePC[]);

	void FprintfPC(const string fileName, const string endString);

	void ScanfPC();

	void FscanfPC(FILE* f);

	void PrintfPC();

	void PrintfFromFilePC(const string fileName);

	void SearchPC();

	int SearchPC(const string find);

	void PrintfTitlePC();

	void FscanfPCOT(FILE* f);

	void InitPC(int id, const string typePC);

};


