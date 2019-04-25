#pragma once

#include "BankAccount.h"


class NormalAccount : public BankAccount
{
private:
	int RoI = 0.3;
	int interest;

public:
	NormalAccount(const char * name, int money, int ID) :BankAccount(name, money, ID),interest(0) {}

	void printNowRoI() {
		cout << "현재 이자는 " << BankAccount::GetDeposits() * RoI << "원 입니다." << endl;
	}

	void depositMoney(int value)
	{
		BankAccount::SetDeposits(value);
		interest += (int)(value * RoI);
	}

};