#pragma once
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h> 
#include <clocale>
#include <Windows.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#define m 100 // Длина массива для исходной строки
#include "lib.h"

void CreateFileS(const char* s) {
	FILE* f;
	int k = 0;
	char c;
	f = fopen(s, "w");
	if (f == NULL) {
		printf("Ошибка при создании файла");
	}
}

bool CheckFile(const char* s)
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
	if (CheckFile(s)) {
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

void inputStringData(char* s, const char* msg, int size)//ввод записей
{
	do {
		printf("%s", msg);
		fseek(stdin, 0, SEEK_END);
		fgets(s, size, stdin);
		trim(s);
		s[strlen(s) - 1] = 0;
		if (strlen(s) < 2)
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
	} while (strlen(s) < 2);
	return;
}

//Проверка ввода ФИО
bool checkName(char* s) {
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
int get_int(const char* msg) {
	char answer[256]; // строка для чтения
	int n = -1; // итоговое целое число
	do {
		printf("%s", msg); // выводим приглашение ко вводу
		fgets(answer, sizeof(answer), stdin); // считываем строку
		trim(answer);
		// пока не будет считано число
		while (sscanf(answer, "%d", &n) != 1) {
			printf("Ошибка ввода, попробуйте еще раз...\n"); // выводим сообщение об ошибке
			_getch();
			fseek(stdin, 0, SEEK_END);
			printf("%s", msg); // выводим приглашение ко вводу
			fgets(answer, sizeof(answer), stdin); // и заново считываем строку
		}
	} while (n < 0);
	return n; // возвращаем корректное целое число
}

bool checkLect(char* s) {
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

void replace(char* str, char findSymb, char rezSymb)
{
	int sizeM = strlen(str);
	for (int i = 0; i < sizeM; i++)
	{
		if (*str == findSymb) *str = rezSymb;
		*str++;
	}
}

bool CheckFillFile(const char* s)
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

void outputLineRecotrds(int index) {
	for (int i = 0; i < index; i++)
		printf("-");
	printf("\n");
}

void outputTitleManagerRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%25s|%10s|\n", " № ", "ФИО", "Адрес", "Ставка");
	outputLineRecotrds(165);
}

void outputTitleClientRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|\n", " № ", "ФИО");
	outputLineRecotrds(165);
}

void outputTitleServiceRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%10s|\n", " № ", "Название", "Тариф");
	outputLineRecotrds(165);
}

void outputTitlePCRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|\n", " № ", "Платформа");
	outputLineRecotrds(165);
}

void outputTitleDataCenterRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " № ", "ФИО клиента", "Тип ПК", "Время взятия", "Время сдачи", "Стоимость", "Услуга", "ФИО менеджера");
	outputLineRecotrds(165);
}

void outputNullSRecotrds() {
	outputLineRecotrds(165);
	//outputUPSRecotrds();
	outputLineRecotrds(165);
	printf("|%163s|\n", "Записей не найдено");
	outputLineRecotrds(165);
}

/*
bool checkStringInFile(char s[m / 2][m / 2]) {
	FILE* f;
	f = fopen("Manager.txt", "r");
	int flag = 0;
	Manager objManager{};
	CreateFileS("tempSearch.txt");
	while (!feof(f))
	{
		objManager = FileDataManager(f);
		int i = 0;
		for (i = 0; s[i][0] != NULL; i++) {
			if (strstr(objManager.FIO, s[i]))
				flag++;
			if (strstr(objManager.adress, s[i]))
				flag++;
		}
		if (flag >= i)
			writeFileManager(objManager, "tempSearch.txt", "\n");
		flag = 0;
	}
	fclose(f);
	ShowManagerDataFile("tempSearch.txt");
	return 0;
}*/
