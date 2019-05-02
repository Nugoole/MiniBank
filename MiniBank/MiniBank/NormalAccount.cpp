#include "NormalAccount.h"

NormalAccount::NormalAccount(const String name, int money, int ID) :BankAccount(name, money, ID), interest(0) {}

void NormalAccount::printNowRoI() const {
	std::cout << "현재 이자는 " << interest << "원 입니다." << endl;
}

void NormalAccount::DepositsMoney(int value)
{
	BankAccount::DepositsMoney(value);
	interest += (int)(value * RoI/100);
	std::cout << interest << endl;
}