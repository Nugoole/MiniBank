#pragma once

#include "BankAccount.h"

class HighCreditAccount : public BankAccount
{
private:
	double RoI = BASIC_ROI;
	double additional_RoI;
	int first_deposits;
	int interest;

public:
	HighCreditAccount(const char * name, int money, int ID, int Credit_Level);

	void printNowRoI() const;

	void DepositsMoney(int value);

	char getCreditLevel() const;
};