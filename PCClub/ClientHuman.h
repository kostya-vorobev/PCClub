#pragma once
#include "Client.h"
#include "Account.h"

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

    ClientHuman operator=(const Client& objClient);

    void ScanfClient();

    void PrintfClient();

    void PrintTitle();
};

