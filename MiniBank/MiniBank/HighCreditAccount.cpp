#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const String name, int money, int ID, int Credit_Level, int original_dep, int interest)
	: BankAccount(name, money, ID), first_deposits(original_dep ? original_dep : money), additional_RoI(Credit_Level), interest(interest) {}

void HighCreditAccount::printNowRoI() const {
	cout << "현재 이자는 " << interest << "원 입니다. " << endl;
}

int HighCreditAccount::getFirstDepos() {
	return first_deposits;
}

int HighCreditAccount::getInterest()
{
	return interest;
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