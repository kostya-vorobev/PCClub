#include "Service.h"

void FprintfServices(Services dataInFileServices, const char* fileName, const char* endString)
{
	FILE* f;
	if (!IsFile(fileName)) {
		CreateFile(fileName);
	}
	if (IsFile(fileName) && dataInFileServices.servicesId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", dataInFileServices.servicesId);
		ReplaceCharacter(&dataInFileServices.name[0], ' ', '_');
		fprintf(f, "%s |", dataInFileServices.name);
		fprintf(f, "%d%s", dataInFileServices.tariff, endString);
		fclose(f);
	}
}

Services ScanfService() {

	Services writingData;
	writingData.servicesId = CountFillFile("Service.txt");
	do {
		InputString(writingData.name, "Введите название услуги: ", 49);
	} while (!IsWord(writingData.name));
	ReplaceCharacter(&writingData.name[0], ' ', '_');
	do {
		writingData.tariff = get_int("Введите тариф услуги: ");
	} while (writingData.tariff <= 1);
	return writingData;
}

Services FileDataService(FILE* f)
{
	Services fileDataObj{};
	fscanf(f, "%d |", &fileDataObj.servicesId);
	fscanf(f, "%s |", fileDataObj.name);
	ReplaceCharacter(&fileDataObj.name[0], '_', ' ');
	fscanf(f, "%d\n", &fileDataObj.tariff);
	return fileDataObj;
}

void PrintfService(Services objService)//вывод всех записей
{
	if (objService.servicesId != 0) {
		printf("|%3d", objService.servicesId);
		printf("|%25s", objService.name);
		printf("|%10d|", objService.tariff);
		printf("\n");
	}
	else {
		PrintfLine(165);
		printf("|%163s|\n", "Записей не найдено");
		PrintfLine(165);
	}
	return;
}

void PrintfFromFileService(const char* s)
{
	FILE* f;
	Services objService{};
	int i = 0;
	if (IsFile(s)) {
		f = fopen(s, "r");
		if (IsFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			PrintfTitleService();
			while (!feof(f)) {
				i++;
				objService = FileDataService(f);
				PrintfService(objService);
			}
			PrintfLine(165);
		}
		else PrintfNullS();
		fclose(f);
	}
	_getch();
}

Services SearchService()
{
	int searchId = 0;
	Services findService;
	do {
		FILE* findInFile;
		findInFile = fopen("Service.txt", "r");
		searchId = get_int("Введите id услуги: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			findService = FileDataService(findInFile);
			if (findService.servicesId == searchId)
			{
				return findService;
			}
		}
	} while (findService.servicesId != searchId);
}
void InitServices(Services* initServices, int id, const char* name, int tariff)
{
	initServices->servicesId = id;
	strcpy(initServices->name, name);
	initServices->tariff = tariff;
}

Services InitServices(int id, const char* name, int tariff)
{
	Services initServices;
	initServices.servicesId = id;
	strcpy(initServices.name, name);
	initServices.tariff = tariff;
	return initServices;
}

int SearchService(Services Original, const char* find)
{
	char ch[10];
	_itoa(Original.servicesId, ch, 10);
	if (strstr(ch, find)) return 1;
	if (strstr(Original.name, find)) return 1;
	_itoa(Original.tariff, ch, 10);
	if (strstr(ch, find)) return 1;
	return 0;

}

void PrintfTitleService() {
	PrintfLine(165);
	printf("|%3s|%25s|%10s|\n", " № ", "Название", "Тариф");
	PrintfLine(165);
}
