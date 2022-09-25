#include "Manager.h"
#include <iostream>

void FprintfManager(Manager dataInFileManager, const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && dataInFileManager.managerId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", dataInFileManager.managerId);
		ReplaceCharacter(&dataInFileManager.fio[0], ' ', '_');
		fprintf(f, "%s |", dataInFileManager.fio);
		ReplaceCharacter(&dataInFileManager.adress[0], ' ', '_');
		fprintf(f, "%s |", dataInFileManager.adress);
		fprintf(f, "%d%s", dataInFileManager.salary, endString);
		fclose(f);
	}
}

Manager ScanfManager()
{
	Manager writingData;
	writingData.managerId = CountFillFile("Manager.txt");
	do {
		InputString(writingData.fio, "Введите ФИО менеджера: ", 49);
	} while (!IsName(writingData.fio));
	ReplaceCharacter(&writingData.fio[0], ' ', '_');
	do {
		InputString(writingData.adress, "Введите адрес менеджера: ", 49);
	} while (!IsWord(writingData.adress));
	ReplaceCharacter(&writingData.adress[0], ' ', '_');
	do {
		writingData.salary = get_int("Введите ставку мененджера: ");
	} while (writingData.salary <= 1);
	return writingData;
}

Manager FscanfManager(FILE* f)
{
	Manager fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.managerId);
	fscanf(f, "%s |", fileDataObj.fio);
	ReplaceCharacter(&fileDataObj.fio[0], '_', ' ');
	fscanf(f, "%s |", fileDataObj.adress);
	ReplaceCharacter(&fileDataObj.adress[0], '_', ' ');
	fscanf(f, "%d\n", &fileDataObj.salary);
	return fileDataObj;
}

Manager SearchManager()
{
	int searchId = 0;
	Manager findManager;
	do {
		FILE* findInFile;
		findInFile = fopen("Manager.txt", "r");
		searchId = get_int("Введите id менеджера: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findManager = FscanfManager(findInFile);
			if (findManager.managerId == searchId)
			{
				return findManager;
			}
		}
	} while (findManager.managerId != searchId);
};

void PrintfManager(Manager objManager)//вывод всех записей
{
	if (objManager.managerId != 0) {
		printf("|%3d", objManager.managerId);
		printf("|%25s", objManager.fio);
		printf("|%25s", objManager.adress);
		printf("|%10d|", objManager.salary);
		printf("\n");
	}
	else {
		PrintfLine(68);
		printf("|%66s|\n", "Записей не найдено");
		PrintfLine(68);
	}
	return;
}

void PrintfFromFileManager(const char* s)
{
	FILE* f;
	Manager objManager{};
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleManager();
			while (!feof(f)) {
				i++;
				objManager = FscanfManager(f);
				PrintfManager(objManager);
			}
			PrintfLine(68);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

bool checkStringInFile(char s[M / 2][M / 2]) {
	FILE* f;
	f = fopen("Manager.txt", "r");
	int flag = 0;
	Manager objManager{};
	CreateFile("tempSearch.txt");
	while (!feof(f))
	{
		objManager = FscanfManager(f);
		int i = 0;
		for (i = 0; s[i][0] != NULL; i++) {
			if (strstr(objManager.fio, s[i]))
				flag++;
			if (strstr(objManager.adress, s[i]))
				flag++;
		}
		if (flag >= i)
			FprintfManager(objManager, "tempSearch.txt", "\n");
		flag = 0;
	}
	fclose(f);
	PrintfFromFileManager("tempSearch.txt");
	return 0;
}

void InitManager(Manager* initManager, int id, const char *fio, const char *adress, int salary)
{
	initManager->managerId = id;
	strcpy(initManager->fio, fio);
	strcpy(initManager->adress, adress);
	initManager->salary = salary;
}

Manager InitManager(int id, const char* fio, const char* adress, int salary)
{
	Manager initManager;
	initManager.managerId = id;
	strcpy(initManager.fio, fio);
	strcpy(initManager.adress, adress);
	initManager.salary = salary;
	return initManager;
}

void PrintfTitleManager() {
	PrintfLine(68);
	printf("|%3s|%25s|%25s|%10s|\n", " № ", "ФИО", "Адрес", "Ставка");
	PrintfLine(68);
}

int SearchManager(Manager Original, const char* find)
{
	char ch[10];
	_itoa(Original.managerId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(Original.fio, find)) return 1;
	if (strstr(Original.adress, find)) return 1;
	_itoa(Original.salary, ch, 10);
	if (strstr(ch, find)) return 1;
	return 0;
}
