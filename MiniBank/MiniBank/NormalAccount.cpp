#include "NormalAccount.h"

NormalAccount::NormalAccount(const char * name, int money, int ID) :BankAccount(name, money, ID), interest(0) {}

void NormalAccount::printNowRoI() const {
	cout << "���� ���ڴ� " << BankAccount::GetDeposits() * RoI << "�� �Դϴ�." << endl;
}

void NormalAccount::DepositsMoney(int value)
{
	BankAccount::DepositsMoney(value);
	interest += (int)(value * RoI);
}

void NormalAccount::withdrawMoney(int value)
{

	BankAccount::withdrawMoney(value);

	cout << "��� �� �ܾ� : " << BankAccount::GetDeposits() << endl;
}