#include "PC.h"

PC::PC(int id, const string typePC)
{
	this->PCId = id;
	this->typePC = typePC;
}

PC::PC()
{
	this->PCId = 0;
	this->typePC = "";
}

PC::~PC()
{
}

void PC::CopyPC(PC objPC)
{
	this->PCId = objPC.PCId;
	this->typePC = objPC.typePC;
}

int PC::GetIDPC()
{
	return this->PCId;
}

string PC::GetTypePC()
{
	return this->typePC;
}

void PC::SetIDPC(int ID)
{
	this->PCId = ID;
}

void PC::SetTypePC(string newTypePC[])
{
	this->typePC += newTypePC->c_str();
}

void PC::FprintfPC(const string fileName, const string endString)
{
	ScanfPC();
	FILE* f;
	if (!Lib::IsFile(fileName)) {
		Lib::CreateFile(fileName);
	}
	if (Lib::IsFile(fileName) && this->PCId != 0) {
		f = fopen(fileName.c_str(), "a");
		fprintf(f, "%d |", this->PCId);
		trim(this->typePC);
		replace(typePC.begin(), typePC.end(), ' ', '_');
		fprintf(f, "%s%s", this->typePC.c_str(), endString.c_str());
		fclose(f);
	}
}

void PC::ScanfPC()
{
	this->PCId = Lib::CountFillFile("PC.txt");
	do {
		Lib::InputString(&this->typePC, "Введите тип ПК: ");
	} while (!Lib::IsWord(this->typePC));
	replace(typePC.begin(), typePC.end(), ' ', '_');
}

void PC::FscanfPC(FILE* f)
{
	fscanf(f, "%d |", &this->PCId);
	fscanf(f, "%s\n", this->typePC.c_str());
	this->typePC = this->typePC.c_str();
	replace(typePC.begin(), typePC.end(), '_', ' ');
}

void PC::PrintfPC()//вывод всех записей
{
	if (this->PCId != 0) {
		printf("|%3d", this->PCId);
		printf("|%25s|", this->typePC.c_str());
		printf("\n");
	}
	else {
		Lib::PrintfLine(32);
		printf("|%30s|\n", "Записей не найдено");
		Lib::PrintfLine(32);
	}
	return;
}

void PC::PrintfFromFilePC(const string fileName)
{
	FILE* f;
	PC objPC{};
	int i = 0;
	if (Lib::IsFile(fileName)) {
		f = fopen(fileName.c_str(), "r");
		if (Lib::IsFillFile(fileName)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitlePC();
			while (!feof(f)) {
				i++;
				this->FscanfPC(f);
				this->PrintfPC();
			}
			Lib::PrintfLine(32);
		}
		else Lib::PrintfNullS();
		fclose(f);
	}
	_getch();
}

void PC::SearchPC()
{
	int searchId = 0;
	do {
		FILE* findInFile;
		findInFile = fopen("PC.txt", "r");
		searchId = Lib::Get_int("Введите id нужного компьютера: ");
		while (!feof(findInFile)) 
		{
			this->FscanfPC(findInFile);
			if (this->PCId == searchId)
			{
				return;
			}
		}
	} while (this->PCId != searchId);
}

int PC::SearchPC(const string find)
{
	string ch;
	ch = to_string(PCId);
	if (ch.find(find)) return 1;
	if (this->typePC.find(find)) return 1;
	return 0;
}

void PC::PrintfTitlePC() {
	Lib::PrintfLine(32);
	printf("|%3s|%25s|\n", " № ", "Платформа");
	Lib::PrintfLine(32);
}

void PC::FscanfPCOT(FILE* f)
{
	fscanf(f, "%d |", &this->PCId);
	fscanf(f, "%s |", this->typePC.c_str());
	this->typePC = this->typePC.c_str();
	replace(typePC.begin(), typePC.end(), '_', ' ');
	return;
}

void PC::InitPC(int id, const string typePC)
{
	this->PCId = id;
	this->typePC = typePC;
}
