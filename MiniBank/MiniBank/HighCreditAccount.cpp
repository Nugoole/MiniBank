#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const char * name, int money, int ID, int Credit_Level)
	:BankAccount(name, money, ID), first_deposits(money), RoI((double)(Credit_Level / 100)), interest(0) {}

void HighCreditAccount::printNowRoI() const {
	cout << "���� ���ڴ� " << (BankAccount::GetDeposits() - first_deposits) * RoI << "�� �Դϴ�. " << endl;
}

void HighCreditAccount::DepositsMoney(int value)
{
	BankAccount::DepositsMoney(value);
	interest += (int)(value * RoI);
}

void HighCreditAccount::withdrawMoney(int value)
{

	BankAccount::withdrawMoney(value);

	cout << "��� �� �ܾ� : " << BankAccount::GetDeposits() << endl;
}

char HighCreditAccount::getCreditLevel() const
{
	if (RoI == (double)(LEVEL_A / 100))
		return 'A';
	else if (RoI == (double)(LEVEL_B / 100))
		return 'B';
	else
		return 'C';
}