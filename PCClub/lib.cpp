#include <iostream>
#include "lib.h"

int Lib::sizeString = 49;

Lib::Lib()
{

};

Lib::~Lib()
{

};

void Lib::CreateFile(const string fileName) {
	FILE* f;
	int k = 0;
	string c;
	f = fopen(fileName.c_str(), "w");
	if (f == NULL) {
		printf("Ошибка при создании файла");
	}
}

bool Lib::IsFile(const string fileName)
{
	FILE* f;
	f = fopen(fileName.c_str(), "r");
	if (f == NULL) {
		return false;
	}
	fclose(f);
	return true;
}

int Lib::CountFillFile(const string fileName)
{
	if (IsFile(fileName)) {
		FILE* f;
		f = fopen(fileName.c_str(), "r");
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

void Lib::InputString(string *str, const string msg)//ввод записей
{
	do {
		printf("%s", msg.c_str());
		fseek(stdin, 0, SEEK_END);
		getline(cin, *str);
		trim(*str);
		//str[str.length() - 1] = 0;
		if ((*str).length() < 2 || (*str).length() > Lib::sizeString)
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
	} while ((*str).length() < 2 || (*str).length() > Lib::sizeString);
	return;
}



//Проверка ввода ФИО
bool Lib::IsName(string str) {
	int flag = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.c_str()[i] == ' ') flag = 1;
		if (str.c_str()[i] != '.' && str.c_str()[i] != ' ')
			if (!(str.c_str()[i] < 'А' || str.c_str()[i] > 'Я')) {}
			else if ((str.c_str()[i] < 'а' || str.c_str()[i] > 'я')) {
				printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
				return false;
			}
	}
	if (flag == 0) return false;
	return true;
}

//Функция ввода числа
int Lib::Get_int(const string msg) {
	string answer; // строка для чтения
	int n = -1; // итоговое целое число
	do {
		printf("%s", msg.c_str()); // выводим приглашение ко вводу
		getline(cin, answer);// считываем строку
		trim(answer);
		// пока не будет считано число
		while (sscanf(answer.c_str(), "%d", &n) != 1) {
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
			_getch();
			fseek(stdin, 0, SEEK_END);
			printf("%s", msg); // выводим приглашение ко вводу
			getline(cin, answer); // и заново считываем строку
		}
	} while (n < 0);
	return n; // возвращаем корректное целое число
}

bool Lib::IsWord(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (str.c_str()[i] != '.' && str.c_str()[i] != ' ')
			if (!(str.c_str()[i] < 'А' || str.c_str()[i] > 'Я')) {}
			else if ((str.c_str()[i] < 'а' || str.c_str()[i] > 'я')) {
				printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
				return false;
			}
	}
	return true;
}

bool Lib::IsFillFile(const string fileName)
{
	FILE* f;
	f = fopen(fileName.c_str(), "r");
	int i = 0;
	while (!feof(f))
	{
		fscanf(f, "%*[^\n]%*c");
		i++;
	}
	if (i == 0) {
		//printf('Файл пустой\n');
		fclose(f);
		return false;
	}
	fclose(f);
	return true;
}

void Lib::PrintfLine(int count) {
	for (int i = 0; i < count; i++)
		printf("-");
	printf("\n");
}

void Lib::PrintfNullS() {
	PrintfLine(165);
	//PrintfUPS();
	PrintfLine(165);
	printf("|%163s|\n", "Записей не найдено");
	PrintfLine(165);
}