#pragma once
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Exceptions.h"

class AccountHandler
{
private:
	BankAccount **acc;
	int accNum;

public:


	AccountHandler();
	void AddAccount();

	BankAccount& operator[](int idx);
	BankAccount * findAcc(int ID);
	void depositMoney();
	int GetAccNum();
	void withdrawMoney();
	void ShowAllAccDeposits();
	~AccountHandler();
};