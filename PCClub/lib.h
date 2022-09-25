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

void CreateFile(const char* s);

bool IsFile(const char* s);

int CountFillFile(const char* s);

void trim(char* s);

void InputString(char* s, const char* msg, int size);

//Проверка ввода ФИО
bool IsName(char* s);

//Функция ввода числа
int Get_int(const char* msg);

bool IsWord(char* s);

void ReplaceCharacter(char* str, char findSymb, char rezSymb);

bool IsFillFile(const char* s);

void PrintfLine(int index);

void PrintfNullS();



















