#include "ClientHuman.h"

ClientHuman::ClientHuman():Client()
{
	this->gender = 0;
	this->age = 0;
	this->sizeLine = 44;
}


ClientHuman::ClientHuman(int id, string name, int gender, int age, string acc):Client(id, name)
{
	this->gender = gender;
	this->age = age;
	this->sizeLine = 44;
	this->acc = acc;
}

ClientHuman::~ClientHuman()
{
}

string ClientHuman::GetAcc() {
	return acc.GetId();
}

ClientHuman ClientHuman::operator=(const Client& objClient) {
	Client::operator=(objClient);
	this->age = 0;
	this->gender = 0;
	return *this;
}
/*
ClientHuman ClientHuman::operator=(const ClientHuman& objClient) {
	Client::operator=(objClient);
	this->age = objClient.age;
	this->gender = objClient.gender;
	return *this;
}*/

void ClientHuman::ScanfClient() {
	Client::ScanfClient();
	do {
		this->gender = Lib::Get_int("������� ��� ������� \n 1 - ���.\n 2 - ���\n: ");
	} while (this->gender < 1 || this->gender > 2);
	do {
		this->age = Lib::Get_int("������� ������� �������: ");
	} while (this->age <= 0);

}

void ClientHuman::SetAge(int age)
{
	this->age = age;
}

void ClientHuman::SetGender(int gender)
{
	this->gender = gender;
}

void ClientHuman::PrintfClient()
{
	if (this->clientId != 0) {
		cout << "|";
		cout.width(3);
		cout << left << this->clientId;
		cout << "|";
		cout.width(25);
		cout << left << this->fio;
		cout << "|";
		cout.width(3);
		cout << left << this->gender;
		cout << "|";
		cout.width(7);
		cout << left << this->age;
		cout << "|" << endl;
	}
	else {
		Lib::PrintfLine(this->sizeLine);
		cout << "|";
		cout.width(30);
		cout << "������� �� �������" << "|" << endl;
		Lib::PrintfLine(this->sizeLine);
	}
	return;

}

void ClientHuman::PrintTitle() {
	
	Lib::PrintfLine(this->sizeLine);
	cout << "|";
	cout.width(3);
	cout << left << "�";
	cout << "|";
	cout.width(25);
	cout << left << "���";
	cout << "|";
	cout.width(3);
	cout << left << "���";
	cout << "|";
	cout.width(7);
	cout << left << "�������";
	cout << "|" << endl;
	Lib::PrintfLine(this->sizeLine);
}

ostream& operator<<(ostream& out, const ClientHuman& client)
{
	out << "id = " << client.clientId << endl;
	out << "��� = " << client.fio << endl;
	out << "��� = " << client.gender << endl;
	out << "������� = " << client.age << endl;
	return out;
}
