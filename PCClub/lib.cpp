#include "lib.h"

void CreateFile(const char* s) {
	FILE* f;
	int k = 0;
	char c;
	f = fopen(s, "w");
	if (f == NULL) {
		printf("������ ��� �������� �����");
	}
}

bool IsFile(const char* s)
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
	if (IsFile(s)) {
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

void InputString(char* s, const char* msg, int size)//���� �������
{
	do {
		printf("%s", msg);
		fseek(stdin, 0, SEEK_END);
		fGets(s, size, stdin);
		trim(s);
		s[strlen(s) - 1] = 0;
		if (strlen(s) < 2)
			printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
	} while (strlen(s) < 2);
	return;
}



//�������� ����� ���
bool IsName(char* s) {
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
int Get_int(const char* msg) {
	char answer[256]; // ������ ��� ������
	int n = -1; // �������� ����� �����
	do {
		printf("%s", msg); // ������� ����������� �� �����
		fGets(answer, sizeof(answer), stdin); // ��������� ������
		trim(answer);
		// ���� �� ����� ������� �����
		while (sscanf(answer, "%d", &n) != 1) {
			printf("������ �����, ���������� ��� ���...\n"); // ������� ��������� �� ������
			_getch();
			fseek(stdin, 0, SEEK_END);
			printf("%s", msg); // ������� ����������� �� �����
			fGets(answer, sizeof(answer), stdin); // � ������ ��������� ������
		}
	} while (n < 0);
	return n; // ���������� ���������� ����� �����
}

bool IsWord(char* s) {
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

void ReplaceCharacter(char* str, char findChar, char rezChar)
{
	int sizeM = strlen(str);
	for (int i = 0; i < sizeM; i++)
	{
		if (*str == findChar) *str = rezChar;
		*str++;
	}
}

bool IsFillFile(const char* s)
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

void PrintfLine(int count) {
	for (int i = 0; i < count; i++)
		printf("-");
	printf("\n");
}

void PrintfNullS() {
	PrintfLine(165);
	//PrintfUPS();
	PrintfLine(165);
	printf("|%163s|\n", "������� �� �������");
	PrintfLine(165);
}