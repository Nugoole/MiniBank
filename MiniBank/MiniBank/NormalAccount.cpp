#include "NormalAccount.h"

NormalAccount::NormalAccount(const String name, int money, int ID, int interest)
	: BankAccount(name, money, ID), interest(interest) {}

void NormalAccount::printNowRoI() const {
	cout << "���� ���ڴ� " << interest << "�� �Դϴ�." << endl;
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