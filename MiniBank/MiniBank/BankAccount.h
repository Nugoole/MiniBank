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
	BankAccount(const char * name = "È«±æµ¿", int money = 0, int ID = 0);
	int GetDeposits() const;
	virtual void DepositsMoney(int val);
	void withdrawMoney(int val);
	int GetAccID();
	char * GetAccName();
	void printDeposits() const;

	virtual void printNowRoI() const = 0;
	virtual char getCreditLevel() const = 0;

	~BankAccount(){
		cout << name << "¼Ò¸ê" << endl;
		delete name;
	}
	
};