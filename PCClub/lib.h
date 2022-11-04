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
#define M 100 // ����� ������� ��� �������� ������
using namespace std;
const static string WHITESPACE = " \n\r\t\f\v";

class Lib
{
	
public:

	static int sizeString;

	Lib();

	~Lib();

	//�������� �����
	void static CreateFile(const string s);

	//�������� ������������� �����
	bool static IsFile(const string fileName);

	//������� ���������� ����� � �����
	int static CountFillFile(const string fileName);

	//�������� �������� � ������ ������
	friend string static ltrim(const string& s);

	//�������� �������� � ����� ������
	friend string static rtrim(const string& s);

	//�������� �������� � ������ � � ����� ������
	friend void static trim(const string& str);

	//������� ����� ������
	void static InputString(string *str, const string msg);

	//�������� ����� ���
	bool static IsName(string str);

	//������� ����� �����
	int static Get_int(const string msg);

	//�������� ����� ����
	bool static IsWord(string str);

	//�������� ������� ������� � �����
	bool static IsFillFile(const string fileName);

	//������ �����
	void static PrintfLine(int index);

	//������ ��� ��������� �������
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