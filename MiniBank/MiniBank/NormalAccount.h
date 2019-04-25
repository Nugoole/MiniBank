#pragma once

#include "BankAccount.h"


class NormalAccount : public BankAccount
{
private:
	int RoI = 0.3;
	int interest;

public:
	NormalAccount(const char * name, int money, int ID);

	void printNowRoI() const;

	void DepositsMoney(int value);

	void withdrawMoney(int value);

	virtual char getCreditLevel() const { return ' '; };
};