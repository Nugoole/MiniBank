#pragma once

#include "BankAccount.h"

class HighCreditAccount : public BankAccount
{
private:
	double RoI;
	int first_deposits;
	int interest;

public:
	HighCreditAccount(const char * name, int money, int ID, int Credit_Level) 
		:BankAccount(name, money, ID),first_deposits(money), RoI((double)(Credit_Level / 100)),interest(0) {}

	void printNowRoI() {
		cout << "현재 이자는 " << (BankAccount::GetDeposits() - first_deposits) * RoI << "원 입니다. " << endl;
	}

	void depositMoney(int value)
	{
		BankAccount::SetDeposits(value);
		interest += (int)(value * RoI);
	}


};