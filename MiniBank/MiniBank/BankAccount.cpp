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
	std::cout << "Ãâ±Ý ÈÄ ÀÜ¾× : " << deposits << endl;	
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
	std::cout << "ÀÜ¾×Àº " << deposits << " ¿ø ÀÔ´Ï´Ù." << endl;
}

BankAccount::~BankAccount() {
	cout << name << "¼Ò¸ê" << endl;
}