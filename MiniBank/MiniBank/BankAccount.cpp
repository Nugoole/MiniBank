#include "BankAccount.h"

BankAccount::BankAccount(const char * name = "ȫ�浿", int money = 0, int ID = 0) 
	:deposits(money), AccountNum(ID)
{
	name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int BankAccount::GetDeposits() const
{
	return deposits;
}

void BankAccount::DepositsMoney(int val)
{
	deposits += val;
}

void BankAccount::withdrawMoney(int val)
{
	deposits -= val;
}

int BankAccount::GetAccID() {
	return AccountNum;
}

char * BankAccount::GetAccName()
{
	return name;
}
void BankAccount::printDeposits() const
{
	cout << "�ܾ��� " << deposits << " �� �Դϴ�." << endl;
}

BankAccount::~BankAccount() {
	cout << name << "�Ҹ�" << endl;
	delete name;
}