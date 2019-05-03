#pragma once

#include "BankAccount.h"


class NormalAccount : public BankAccount
{
private:
	double RoI = BASIC_ROI;
	int interest;

public:
	NormalAccount(const String name, int money, int ID, int interest = 0);

	int  getInterest();

	void printNowRoI() const;

	void DepositsMoney(int value);

	int getFirstDepos() { return 0; }

	virtual char getCreditLevel() const { return 'D'; };
};