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



void CreateFileS(const char* s);

bool CheckFile(const char* s);

int CountFillFile(const char* s);

void trim(char* s);

void inputStringData(char* s, const char* msg, int size);

//Проверка ввода ФИО
bool checkName(char* s);

//Функция ввода числа
int get_int(const char* msg);

bool checkLect(char* s);

void replace(char* str, char findSymb, char rezSymb);

bool CheckFillFile(const char* s);

void outputLineRecotrds(int index);

void outputTitleManagerRecotrds();

void outputTitleClientRecotrds();

void outputTitleServiceRecotrds();

void outputTitlePCRecotrds();

void outputTitleDataCenterRecotrds();

void outputNullSRecotrds();

