#include "NormalAccount.h"

NormalAccount::NormalAccount(const String name, int money, int ID, int interest)
	: BankAccount(name, money, ID), interest(interest) {}

void NormalAccount::printNowRoI() const {
	cout << "현재 이자는 " << interest << "원 입니다." << endl;
}

int NormalAccount::getInterest()
{
	return interest;
}

void NormalAccount::DepositsMoney(int value)
{
	BankAccount::DepositsMoney(value);
	interest += (int)(value * RoI/100);
	cout << interest << endl;
}