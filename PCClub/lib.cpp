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
		printf("������ ��� �������� �����");
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

void Lib::InputString(string *str, const string msg)//���� �������
{
	do {
		printf("%s", msg.c_str());
		fseek(stdin, 0, SEEK_END);
		getline(cin, *str);
		trim(*str);
		//str[str.length() - 1] = 0;
		if ((*str).length() < 2 || (*str).length() > Lib::sizeString)
			printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
	} while ((*str).length() < 2 || (*str).length() > Lib::sizeString);
	return;
}



//�������� ����� ���
bool Lib::IsName(string str) {
	int flag = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.c_str()[i] == ' ') flag = 1;
		if (str.c_str()[i] != '.' && str.c_str()[i] != ' ')
			if (!(str.c_str()[i] < '�' || str.c_str()[i] > '�')) {}
			else if ((str.c_str()[i] < '�' || str.c_str()[i] > '�')) {
				printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
				return false;
			}
	}
	if (flag == 0) return false;
	return true;
}

//������� ����� �����
int Lib::Get_int(const string msg) {
	string answer; // ������ ��� ������
	int n = -1; // �������� ����� �����
	do {
		printf("%s", msg.c_str()); // ������� ����������� �� �����
		getline(cin, answer);// ��������� ������
		trim(answer);
		// ���� �� ����� ������� �����
		while (sscanf(answer.c_str(), "%d", &n) != 1) {
			printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
			_getch();
			fseek(stdin, 0, SEEK_END);
			printf("%s", msg); // ������� ����������� �� �����
			getline(cin, answer); // � ������ ��������� ������
		}
	} while (n < 0);
	return n; // ���������� ���������� ����� �����
}

bool Lib::IsWord(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (str.c_str()[i] != '.' && str.c_str()[i] != ' ')
			if (!(str.c_str()[i] < '�' || str.c_str()[i] > '�')) {}
			else if ((str.c_str()[i] < '�' || str.c_str()[i] > '�')) {
				printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
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
		//printf('���� ������\n');
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
	printf("|%163s|\n", "������� �� �������");
	PrintfLine(165);
}