#pragma once

#include "BankAccount.h"

class HighCreditAccount : public BankAccount
{
private:
	double RoI;
	int first_deposits;
	int interest;

public:
	HighCreditAccount(const char * name, int money, int ID, int Credit_Level);

	void printNowRoI() const;

	void DepositsMoney(int value);

	void withdrawMoney(int value);

	char getCreditLevel() const;
};