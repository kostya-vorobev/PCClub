#include "lib.h"

void CreateFile(const char* s) {
	FILE* f;
	int k = 0;
	char c;
	f = fopen(s, "w");
	if (f == NULL) {
		printf("Ошибка при создании файла");
	}
}

bool IsFile(const char* s)
{
	FILE* f;
	f = fopen(s, "r");
	if (f == NULL) {
		return false;
	}
	fclose(f);
	return true;
}

int CountFillFile(const char* s)
{
	if (IsFile(s)) {
		FILE* f;
		f = fopen(s, "r");
		int i = 0;
		while (!feof(f))
		{
			fscanf(f, "%*[^\n]%*c");
			i++;
		}
		if (i <= 1) {
			fclose(f);
			return 1;
		}
		fclose(f);
		return i;
	} return 1;

}

void trim(char* s)
{
	// удаляем пробелы и табы с начала строки:
	int i = 0, j;
	while ((s[i] == ' ') || (s[i] == '\t'))
	{
		i++;
	}
	if (i > 0)
	{
		for (j = 0; j < strlen(s); j++)
		{
			s[j] = s[j + i];
		}
		s[j] = '\0';
	}

	// удаляем пробелы и табы с конца строки:
	i = strlen(s) - 1;
	while ((s[i] == ' ') || (s[i] == '\t'))
	{
		i--;
	}
	if (i < (strlen(s) - 1))
	{
		s[i + 1] = '\0';
	}
}

void InputString(char* s, const char* msg, int size)//ввод записей
{
	do {
		printf("%s", msg);
		fseek(stdin, 0, SEEK_END);
		fGets(s, size, stdin);
		trim(s);
		s[strlen(s) - 1] = 0;
		if (strlen(s) < 2)
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
	} while (strlen(s) < 2);
	return;
}



//Проверка ввода ФИО
bool IsName(char* s) {
	int flag = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ') flag = 1;
		if (s[i] != '.' && s[i] != ' ')
			if (!(s[i] < 'А' || s[i] > 'Я')) {}
			else if ((s[i] < 'а' || s[i] > 'я')) {
				printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
				return false;
			}
	}
	if (flag == 0) return false;
	return true;
}

//Функция ввода числа
int Get_int(const char* msg) {
	char answer[256]; // строка для чтения
	int n = -1; // итоговое целое число
	do {
		printf("%s", msg); // выводим приглашение ко вводу
		fGets(answer, sizeof(answer), stdin); // считываем строку
		trim(answer);
		// пока не будет считано число
		while (sscanf(answer, "%d", &n) != 1) {
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
			_getch();
			fseek(stdin, 0, SEEK_END);
			printf("%s", msg); // выводим приглашение ко вводу
			fGets(answer, sizeof(answer), stdin); // и заново считываем строку
		}
	} while (n < 0);
	return n; // возвращаем корректное целое число
}

bool IsWord(char* s) {
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != '.' && s[i] != ' ')
			if (!(s[i] < 'А' || s[i] > 'Я')) {}
			else if ((s[i] < 'а' || s[i] > 'я')) {
				printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
				return false;
			}
	}
	return true;
}

void ReplaceCharacter(char* str, char findChar, char rezChar)
{
	int sizeM = strlen(str);
	for (int i = 0; i < sizeM; i++)
	{
		if (*str == findChar) *str = rezChar;
		*str++;
	}
}

bool IsFillFile(const char* s)
{
	FILE* f;
	f = fopen(s, "r");
	int i = 0;
	while (!feof(f))
	{
		fscanf(f, "%*[^\n]%*c");
		i++;
	}
	if (i == 0) {
		//printf("Файл пустой\n");
		fclose(f);
		return false;
	}
	fclose(f);
	return true;
}

void PrintfLine(int count) {
	for (int i = 0; i < count; i++)
		printf("-");
	printf("\n");
}

void PrintfNullS() {
	PrintfLine(165);
	//PrintfUPS();
	PrintfLine(165);
	printf("|%163s|\n", "Записей не найдено");
	PrintfLine(165);
}