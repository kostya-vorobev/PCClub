#include "Client.h"

Client::Client(int id, const string fio)
{
	this->clientId = id;
	this->fio = fio;
	this->sizeLine = 31;
}

Client::Client()
{
	this->clientId = 0;
	this->fio = "";
	this->sizeLine = 31;
}

Client::~Client()
{
}

void Client::CopyClient(Client objClient)
{
	 this->clientId = objClient.clientId;
	 this->fio = objClient.fio;
}
/*
Client Client::operator=(const Client& objClient)
{
	this->clientId = objClient.clientId;
	this->fio = objClient.fio;
	return *this;
}
*/
int Client::GetIDClient()
{
	return this->clientId;
}

string Client::GetFio()
{
	return this->fio;
}

void Client::SetIDClient(int id)
{
	this->clientId = id;
}

Client Client::operator=(const Client& objClient)
{
	this->clientId = objClient.clientId;
	this->fio = objClient.fio;
	return *this;
}

void Client::SetFio(string fio)
{
	this->fio = fio;
}

void FscanfFile(vector<Client>* client, string fileName)
{
	int i = 0;
	Client clientBuffer;
	try {
		if (Lib::IsFile(fileName)) {
			ifstream fout(fileName, ios::in);
			if (Lib::IsFillFile(fileName)) {
				fout.seekg(0, ios::beg);
				string fileLine;
				while (getline(fout, fileLine)) {
					i++;
					clientBuffer.FscanfClient(fileLine);
					client->push_back(clientBuffer);
				}
			}
			fout.close();
		}
		else throw exception("Файл не найден!");
	}
	catch (const exception& e)
	{
		cout << e.what();
	}
}


void Client::FprintfClient(const string fileName, const string endString)
{
	ScanfClient();
	ofstream f(fileName, ios_base::app);
	if (!f.is_open()) {
		Lib::CreateFile(fileName);
	}
	if (Lib::IsFile(fileName) && this->clientId != 0) {
		f << this->clientId;
		f << " |";
		f << this->fio;
		f << endl;
	}
	f.close();
}

void Client::ScanfClient()
{
	try {
		this->clientId = Lib::CountFillFile("Client.txt");
		do {
			Lib::InputString(&this->fio, "Введите ФИО клиента: ");
		} while (!Lib::IsName(this->fio));
		replace(fio.begin(), fio.end(), ' ', '_');
	}
	catch (const exception& e)
	{
		cout << e.what();
		_getch();
	}

}

void Client::FscanfClient(string fileLine)
{
	istringstream split(fileLine);
	vector<string> words;
	char split_char = '|';
	for (string each; getline(split, each, split_char); words.push_back(each));
	if (words.size() > 2) throw exception("Файл был поврежден, программа может работать некорректно");
	trim(words[0]);
	this->clientId = atoi(words[0].c_str());
	this->fio = words[1];
	replace(fio.begin(), fio.end(), '_', ' ');
}

void Client::PrintfClient()//вывод всех записей
{
	if (this->clientId != 0) {
		cout << "|";
		cout.width(3);
		cout << left << this->clientId;
		cout << "|";
		cout.width(25);
		cout << left << this->fio;
		cout << "|" << endl;
	}
	else {
		Lib::PrintfLine(this->sizeLine);
		cout << "|";
		cout.width(30);
		cout << "Записей не найдено" << "|" << endl;
		Lib::PrintfLine(this->sizeLine);
	}
	return;
}

void Client::SearchClient()
{
	int searchId = 0;
	try {
		do {
			ifstream fout("Client.txt", ios::in);
			searchId = Lib::Get_int("Введите id клиента: ");
			string fileLine;
			while (getline(fout, fileLine)) //Считывание во временный файл
			{
				this->FscanfClient(fileLine);
				if (this->clientId == searchId)
				{
					return;
				}
			}
		} while (this->clientId != searchId);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

}

void Client::PrintfFromFileClient(const string fileName)
{
	int i = 0;
	try {
		if (Lib::IsFile(fileName)) {
			ifstream fout(fileName, ios::in);
			if (Lib::IsFillFile(fileName)) {
				fout.seekg(0, ios::beg);
				string fileLine;
				PrintTitle();
				while (getline(fout,fileLine)) {
					i++;
					this->FscanfClient(fileLine);
					this->PrintfClient();
				}
				Lib::PrintfLine(32);
			}
			else Lib::PrintfNullS();
			fout.close();
		}
		else throw exception("Файл не найден!");
	}
	catch (const exception& e)
	{
		cout << e.what();
	}
	_getch();
}

int Client::SearchClient(const string find)
{
	string ch;
	ch = to_string(this->clientId);
	if (ch.find(find)) return 1;
	if (this->fio.find(find)) return 1;
	return 0;
}

void Client::PrintTitle() {
	Lib::PrintfLine(this->sizeLine);
	map <string, int> title = { {"№",3 },
								{"ФИО", 25} };
	map <string, int>::iterator it;
	for (it = title.begin(); it != title.end(); it++)
	{
		cout << "|";
		cout.width(it->second);
		cout << left << it->first;

	}
	cout << "|" << endl;
	Lib::PrintfLine(this->sizeLine);
}

void Client::FscanfClientOT(vector<string> words)
{
	trim(words[8]);
	this->clientId = atoi(words[8].c_str());
	this->fio = words[9];
	replace(fio.begin(), fio.end(), '_', ' ');
	return;
}

void Client::InitClient(int id, const string fio)
{
	this->clientId = id;
	this->fio = fio;
}

bool operator<(const Client& left, const Client& right)
{
	return left.clientId < right.clientId;
}

bool operator>(const Client& left, const Client& right)
{
	return left.clientId > right.clientId;
}

ostream& operator<<(ostream& out, const Client& client)
{
	out << "id = " << client.clientId << endl;
	out << "ФИО = " << client.fio << endl;
	return out;
}

