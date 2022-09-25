#include "PC.h"

PC::PC(int id, const char* typePC)
{
	this->PCId = id;
	strcpy(this->typePC, typePC);
}

PC::PC()
{
}

PC::~PC()
{
}

void PC::CopyPC(PC objPC)
{
	this->PCId = objPC.PCId;
	strcpy(this->typePC, objPC.typePC);
}

int PC::getIDPC()
{
	return this->PCId;
}

char* PC::getTypePC()
{
	return this->typePC;
}

void PC::setIDPC(int ID)
{
	this->PCId = ID;
}

void PC::setTypePC(char newTypePC[])
{
	strcat(this->typePC, newTypePC);
}

void PC::FprintfPC(const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && this->PCId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", this->PCId);
		ReplaceCharacter(&this->typePC[0], ' ', '_');
		fprintf(f, "%s%s", this->typePC, endString);
		fclose(f);
	}
}

PC PC::ScanfPC()
{
	PC writingData;
	writingData.PCId = CountFillFile("PC.txt");
	do {
		InputString(writingData.typePC, "Введите тип ПК: ", 49);
	} while (!IsWord(writingData.typePC));
	ReplaceCharacter(&writingData.typePC[0], ' ', '_');
	return writingData;
}

PC PC::FileDataPC(FILE* f)
{
	PC fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.PCId);
	fscanf(f, "%s\n", fileDataObj.typePC);
	ReplaceCharacter(&fileDataObj.typePC[0], '_', ' ');
	return fileDataObj;
}

void PC::PrintfPC()//вывод всех записей
{
	if (this->PCId != 0) {
		printf("|%3d", this->PCId);
		printf("|%25s|", this->typePC);
		printf("\n");
	}
	else {
		PrintfLine(165);
		printf("|%163s|\n", "Записей не найдено");
		PrintfLine(165);
	}
	return;
}

void PC::PrintfFromFilePC(const char* s)
{
	FILE* f;
	PC objPC{};
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitlePC();
			while (!feof(f)) {
				i++;
				this->FileDataPC(f);
				this->PrintfPC();
			}
			PrintfLine(165);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

PC PC::SearchPC()
{
	int searchId = 0;
	PC findPC;
	do {
		FILE* findInFile;
		findInFile = fopen("PC.txt", "r");
		searchId = get_int("Введите id нужного компьютера: ");
		while (!feof(findInFile)) 
		{
			findPC = FileDataPC(findInFile);
			if (findPC.PCId == searchId)
			{
				return findPC;
			}
		}
	} while (findPC.PCId != searchId);
}

int PC::SearchPC(const char* find)
{
	char ch[10];
	_itoa(this->PCId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(this->typePC, find)) return 1;
	return 0;
}

void PC::PrintfTitlePC() {
	PrintfLine(165);
	printf("|%3s|%25s|\n", " № ", "Платформа");
	PrintfLine(165);
}

void PC::FscanfPCOT(FILE* f)
{
	fscanf(f, "%d |", &this->PCId);
	fscanf(f, "%s |", this->typePC);
	ReplaceCharacter(&typePC[0], '_', ' ');
	return;
}

void PC::InitPC(int id, const char* typePC)
{
	this->PCId = id;
	strcpy(this->typePC, typePC);
}
