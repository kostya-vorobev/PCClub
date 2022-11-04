#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h> 
#include <clocale>
#include <Windows.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <algorithm>
#include <string>
#include <iostream>
#define M 100 // Длина массива для исходной строки
using namespace std;
const static string WHITESPACE = " \n\r\t\f\v";

class Lib
{
	
public:

	static int sizeString;

	Lib();

	~Lib();

	//Создание файла
	void static CreateFile(const string s);

	//Проверка существования файла
	bool static IsFile(const string fileName);

	//Подсчет количества строк в файле
	int static CountFillFile(const string fileName);

	//Удаление пробелов в начале строки
	friend string static ltrim(const string& s);

	//Удаление пробелов в конце строки
	friend string static rtrim(const string& s);

	//Удаление пробелов в начале и в конце строки
	friend void static trim(const string& str);

	//Функция ввода строки
	void static InputString(string *str, const string msg);

	//Проверка ввода ФИО
	bool static IsName(string str);

	//Функция ввода числа
	int static Get_int(const string msg);

	//Проверка ввода слов
	bool static IsWord(string str);

	//Проврека наличия записей в файле
	bool static IsFillFile(const string fileName);

	//Печать линии
	void static PrintfLine(int index);

	//Печать при отстутвии записей
	void static PrintfNullS();

};

string ltrim(const string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

void trim(const string& str)
{
	rtrim(ltrim(str));
}