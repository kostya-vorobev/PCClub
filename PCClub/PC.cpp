#include "lib.h"
#include "PC.h"


PC::PC(int newID, char newTypePC[])
{
	this->PCId = newID;
	strcat(this->typePC, newTypePC);
}

PC::PC(int newID)
{
	this->PCId = newID;
}

PC::PC()
{
}

PC::~PC()
{
}

int PC::getID()
{
	return this->PCId;
}

char* PC::getTypePC()
{
	return this->typePC;
}

void PC::setID(int ID)
{
	this->PCId = ID;
}

void PC::setTypePC(char newTypePC[])
{
	strcat(this->typePC, newTypePC);
}

void PC::writeFilePC(const char* fileName)
{
	FILE* f;
	if (!CheckFile(fileName)) {
		CreateFileS(fileName);
	}
	if (CheckFile(fileName) && PCId != 0) {
		f = fopen(fileName, "a");
		fprintf(f, "%d |", PCId);
		replace(&typePC[0], ' ', '_');
		fprintf(f, "%s\n", typePC);
		fclose(f);
	}
}

void PC::PCWriteUser()
{
	PCId = CountFillFile("PC.txt");
	do {
		inputStringData(typePC, "Введите тип ПК: ", 49);
	} while (!checkLect(typePC));
	replace(&typePC[0], ' ', '_');
	return;
}

void PC::outputPCRecotrds()//вывод всех записей
{
	if (PCId != 0) {
		printf("|%3d", PCId);
		printf("|%25s|", typePC);
		printf("\n");
	}
	else {
		outputLineRecotrds(165);
		printf("|%32s|\n", "Записей не найдено");
		outputLineRecotrds(165);
	}
	return;
}

void PC::ShowPCDataFile(const char* s)
{
	FILE* f;
	int i = 0;
	if (CheckFile(s)) {
		f = fopen(s, "r");
		if (CheckFillFile(s)) {
			fseek(f, 0, SEEK_SET);
			outputTitlePCRecotrds();
			while (!feof(f)) {
				i++;
				FileDataPC(f);
				outputPCRecotrds();
			}
			outputLineRecotrds(32);
		}
		else outputNullSRecotrds();
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
		searchId = get_int("Введите id нужного компьютера: ");
		while (!feof(findInFile)) //Считывание во временный файл
		{
			FileDataPC(findInFile);
			if (PCId == searchId)
			{
				return;
			}
		}
	} while (PCId != searchId);
};

void PC::FileDataPC(FILE* f)
{
	fscanf(f, "%d |", &PCId);
	fscanf(f, "%s\n", typePC);
	replace(&typePC[0], '_', ' ');
	return;
}

void PC::FileDataPCDC(FILE* f)
{
	fscanf(f, "%d |", &PCId);
	fscanf(f, "%s |", typePC);
	replace(&typePC[0], '_', ' ');
	return;
}