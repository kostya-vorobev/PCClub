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
#define M 100 // ����� ������� ��� �������� ������
using namespace std;
const static string WHITESPACE = " \n\r\t\f\v";

class Lib
{
public:
	//�������� �����
	void static CreateFile(const string s);

	//�������� ������������� �����
	bool static IsFile(const string fileName);

	//������� ���������� ����� � �����
	int static CountFillFile(const string fileName);

	//�������� �������� � ������ ������
	string static ltrim(const string& s);

	//�������� �������� � ����� ������
	string static rtrim(const string& s);

	//�������� �������� � ������ � � ����� ������
	void static trim(const string& str);

	//������� ����� ������
	void static InputString(string *str, const string msg, int size);

	//�������� ����� ���
	bool static IsName(string str);

	//������� ����� �����
	int static Get_int(const string msg);

	//�������� ����� ����
	bool static IsWord(string str);

	//������� ������ �������� � ������
	void static ReplaceCharacter(string str, string findSymb, string rezSymb);

	//�������� ������� ������� � �����
	bool static IsFillFile(const string fileName);

	//������ �����
	void static PrintfLine(int index);

	//������ ��� ��������� �������
	void static PrintfNullS();

};
