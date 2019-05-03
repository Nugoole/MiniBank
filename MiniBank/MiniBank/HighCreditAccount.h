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
	HighCreditAccount(const String name, int money, int ID, int Credit_Level, int original_dep = 0, int interest = 0);

	int  getInterest();

	void printNowRoI() const;

	void DepositsMoney(int value);

	int getFirstDepos();

	char getCreditLevel() const;
};