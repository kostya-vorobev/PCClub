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
#define m 100 // ����� ������� ��� �������� ������
#include "lib.h"

void CreateFileS(const char* s) {
	FILE* f;
	int k = 0;
	char c;
	f = fopen(s, "w");
	if (f == NULL) {
		printf("������ ��� �������� �����");
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
	// ������� ������� � ���� � ������ ������:
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

	// ������� ������� � ���� � ����� ������:
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

void inputStringData(char* s, const char* msg, int size)//���� �������
{
	do {
		printf("%s", msg);
		fseek(stdin, 0, SEEK_END);
		fgets(s, size, stdin);
		trim(s);
		s[strlen(s) - 1] = 0;
		if (strlen(s) < 2)
			printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
	} while (strlen(s) < 2);
	return;
}

//�������� ����� ���
bool checkName(char* s) {
	int flag = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ') flag = 1;
		if (s[i] != '.' && s[i] != ' ')
			if (!(s[i] < '�' || s[i] > '�')) {}
			else if ((s[i] < '�' || s[i] > '�')) {
				printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
				return false;
			}
	}
	if (flag == 0) return false;
	return true;
}

//������� ����� �����
int get_int(const char* msg) {
	char answer[256]; // ������ ��� ������
	int n = -1; // �������� ����� �����
	do {
		printf("%s", msg); // ������� ����������� �� �����
		fgets(answer, sizeof(answer), stdin); // ��������� ������
		trim(answer);
		// ���� �� ����� ������� �����
		while (sscanf(answer, "%d", &n) != 1) {
			printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
			_getch();
			fseek(stdin, 0, SEEK_END);
			printf("%s", msg); // ������� ����������� �� �����
			fgets(answer, sizeof(answer), stdin); // � ������ ��������� ������
		}
	} while (n < 0);
	return n; // ���������� ���������� ����� �����
}

bool checkLect(char* s) {
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != '.' && s[i] != ' ')
			if (!(s[i] < '�' || s[i] > '�')) {}
			else if ((s[i] < '�' || s[i] > '�')) {
				printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
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
		//printf("���� ������\n");
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
	printf("|%3s|%25s|%25s|%10s|\n", " � ", "���", "�����", "������");
	outputLineRecotrds(165);
}

void outputTitleClientRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|\n", " � ", "���");
	outputLineRecotrds(165);
}

void outputTitleServiceRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%10s|\n", " � ", "��������", "�����");
	outputLineRecotrds(165);
}

void outputTitlePCRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|\n", " � ", "���������");
	outputLineRecotrds(165);
}

void outputTitleDataCenterRecotrds() {
	outputLineRecotrds(165);
	printf("|%3s|%25s|%25s|%12s|%10s|%10s|%25s|%25s|\n", " � ", "��� �������", "��� ��", "����� ������", "����� �����", "���������", "������", "��� ���������");
	outputLineRecotrds(165);
}

void outputNullSRecotrds() {
	outputLineRecotrds(165);
	//outputUPSRecotrds();
	outputLineRecotrds(165);
	printf("|%163s|\n", "������� �� �������");
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
