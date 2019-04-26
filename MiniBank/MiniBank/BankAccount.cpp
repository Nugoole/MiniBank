#include "BankAccount.h"

BankAccount::BankAccount(const char * name, int money, int ID) 
	:deposits(money), AccountNum(ID)
{
	this->name = new char[strlen(name) + 1];
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
	cout << "Ãâ±Ý ÈÄ ÀÜ¾× : " << deposits << endl;	
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
	cout << "ÀÜ¾×Àº " << deposits << " ¿ø ÀÔ´Ï´Ù." << endl;
}

BankAccount::~BankAccount() {
	cout << name << "¼Ò¸ê" << endl;
	delete name;
}