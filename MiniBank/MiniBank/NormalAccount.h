#pragma once

#include "BankAccount.h"


class NormalAccount : public BankAccount
{
private:
	double RoI = BASIC_ROI;
	int interest;

public:
	NormalAccount(const char * name, int money, int ID);

	void printNowRoI() const;

	void DepositsMoney(int value);

	virtual char getCreditLevel() const { return ' '; };
};