#pragma once
#include <iostream>

using namespace std;

enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

enum { NORMAL = 1, CREDIT = 2 };

class BankAccount
{
private:	
	char * name;
	int deposits;
	int AccountNum;
	

public:
	BankAccount(const char * name = "ȫ�浿", int money = 0, int ID = 0) :deposits(money), AccountNum(ID)
	{
		strcpy(this->name, name);
	}

	int GetDeposits()
	{
		return deposits;
	}

	void SetDeposits(int val)
	{
		deposits += val;
	}

	virtual void printNowRoI() const = 0;
	
};