#include "NormalAccount.h"

NormalAccount::NormalAccount(const char * name, int money, int ID) :BankAccount(name, money, ID), interest(0) {}

void NormalAccount::printNowRoI() const {
	cout << "현재 이자는 " << BankAccount::GetDeposits() * RoI << "원 입니다." << endl;
}

void NormalAccount::DepositsMoney(int value)
{
	BankAccount::DepositsMoney(value);
	interest += (int)(value * RoI);
}

void NormalAccount::withdrawMoney(int value)
{

	BankAccount::withdrawMoney(value);

	cout << "출금 후 잔액 : " << BankAccount::GetDeposits() << endl;
}