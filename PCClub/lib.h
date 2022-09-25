#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
#define M 100 // Длина массива для исходной строки

//Создание файла
void CreateFile(const char* s);

//Проверка существования файла
bool IsFile(const char* s);

//Подсчет количества строк в файле
int CountFillFile(const char* s);

//Удаление пробелов в начале и в конце строки
void trim(char* s);

//Функция ввода строки
void InputString(char* s, const char* msg, int size);

//Проверка ввода ФИО
bool IsName(char* s);

//Функция ввода числа
int Get_int(const char* msg);

//Проверка ввода слов
bool IsWord(char* s);

//Функция замены символов в строке
void ReplaceCharacter(char* str, char findSymb, char rezSymb);

//Проврека наличия записей в файле
bool IsFillFile(const char* s);

//Печать линии
void PrintfLine(int index);

//Печать при отстутвии записей
void PrintfNullS();


















