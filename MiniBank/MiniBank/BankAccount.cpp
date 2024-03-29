#include "BankAccount.h"


BankAccount::BankAccount(const String name, int money, int ID) 
	:deposits(money), AccountNum(ID)
{
	if (money < 0)
		throw NegativeMoneyInputException(money);

	this->name = name;
}

int BankAccount::GetDeposits() const
{
	return deposits;
}

void BankAccount::DepositsMoney(int val)
{
	if (val < 0)
		throw NegativeMoneyInputException(val);

	deposits += val;
}

void BankAccount::withdrawMoney(int val)
{
	if (val > deposits)
		throw WithdrawException(val);

	deposits -= val;
	cout << "��� �� �ܾ� : " << deposits << endl;	
}

int BankAccount::GetAccID() {
	return AccountNum;
}

String& BankAccount::GetAccName()
{
	return name;
}
void BankAccount::printDeposits() const
{
	cout << "�ܾ��� " << deposits << " �� �Դϴ�." << endl;
}

BankAccount::~BankAccount() {
	cout << name << "�Ҹ�" << endl;
}