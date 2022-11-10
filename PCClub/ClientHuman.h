#pragma once
#include "Client.h"
#include "Account.h"
#include <xkeycheck.h>

class ClientHuman :
    public Client
{
protected: 
    int gender;
    int age;
    int sizeLine;
    Account<string> acc;

public:

    ClientHuman();

    ClientHuman(int id, string name, int gender, int age, string acc);

    ~ClientHuman();

    string GetAcc();

    void SetAge(int age);

    void SetGender(int Gender);

    void FscanfClient(string fileLine);

    //void FscanfFile(vector<ClientHuman>* client, string fileName);

    ClientHuman operator=(const Client& objClient);

    friend ostream& operator<< (ostream& out, const ClientHuman& client);

    void ScanfClient();

    void PrintfClient();

    void PrintTitle();
};
