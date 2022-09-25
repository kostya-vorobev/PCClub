#include "PC.h"

void FprintfPC(PC dataInFilePC, const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && dataInFilePC.PCId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", dataInFilePC.PCId);
		ReplaceCharacter(&dataInFilePC.typePC[0], ' ', '_');
		fprintf(f, "%s%s", dataInFilePC.typePC, endString);
		fclose(f);
	}
}

PC ScanfPC()
{
	PC writingData;
	writingData.PCId = CountFillFile("PC.txt");
	do {
		InputString(writingData.typePC, "Введите тип ПК: ", 49);
	} while (!IsWord(writingData.typePC));
	ReplaceCharacter(&writingData.typePC[0], ' ', '_');
	return writingData;
}

PC FscanfPC(FILE* f)
{
	PC fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.PCId);
	fscanf(f, "%s\n", fileDataObj.typePC);
	ReplaceCharacter(&fileDataObj.typePC[0], '_', ' ');
	return fileDataObj;
}

void PrintfPC(PC objPC)//вывод всех записей
{
	if (objPC.PCId != 0) {
		printf("|%3d", objPC.PCId);
		printf("|%25s|", objPC.typePC);
		printf("\n");
	}
	else {
		PrintfLine(32);
		printf("|%30s|\n", "Записей не найдено");
		PrintfLine(32);
	}
	return;
}

void PrintfFromFilePC(const char* s)
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
				objPC = FscanfPC(f);
				PrintfPC(objPC);
			}
			PrintfLine(32);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

PC SearchPC()
{
	int searchId = 0;
	PC findPC;
	do {
		FILE* findInFile;
		findInFile = fopen("PC.txt", "r");
		searchId = get_int("Введите id нужного компьютера: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findPC = FscanfPC(findInFile);
			if (findPC.PCId == searchId)
			{
				return findPC;
			}
		}
	} while (findPC.PCId != searchId);
}

void InitPC(PC* initPC, int id, const char* typePC)
{
	initPC->PCId = id;
	strcpy(initPC->typePC, typePC);
}

PC InitPC(int id, const char* typePC)
{
	PC initPC;
	initPC.PCId = id;
	strcpy(initPC.typePC, typePC);
	return initPC;
}

int SearchPC(PC Original, const char* find)
{
	char ch[10];
	_itoa(Original.PCId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(Original.typePC, find)) return 1;
	return 0;
}

void PrintfTitlePC() {
	PrintfLine(32);
	printf("|%3s|%25s|\n", " № ", "Платформа");
	PrintfLine(32);
}