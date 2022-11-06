#pragma once
#include "lib.h"

class IBase
{
protected:
	string fio;
public:
	virtual void SetFio(string fio) = 0;
	virtual string GetFio() = 0;
	virtual ~IBase() = default;
	virtual void PrintTitle() = 0;

};

