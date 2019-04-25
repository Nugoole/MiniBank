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
		cout << "���� ���ڴ� " << BankAccount::GetDeposits() * RoI << "�� �Դϴ�." << endl;
	}

	void depositMoney(int value)
	{
		BankAccount::SetDeposits(value);
		interest += (int)(value * RoI);
	}

};