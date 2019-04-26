#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const char * name, int money, int ID, int Credit_Level)
	:BankAccount(name, money, ID), first_deposits(money), additional_RoI(Credit_Level), interest(0) {}

void HighCreditAccount::printNowRoI() const {
	cout << "현재 이자는 " << interest << "원 입니다. " << endl;
}

void HighCreditAccount::DepositsMoney(int value)
{
	BankAccount::DepositsMoney(value);
	interest += (int)(value * ((double)(additional_RoI/100) + RoI/100));
	cout << interest << endl;
}

char HighCreditAccount::getCreditLevel() const
{
	if (additional_RoI == LEVEL_A)
		return 'A';
	else if (additional_RoI == LEVEL_B)
		return 'B';
	else
		return 'C';
}