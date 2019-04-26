#pragma once
#include "NormalAccount.h"
#include "HighCreditAccount.h"

class AccountHandler
{
private:
	BankAccount *acc[MAX_ACC_NUM];
	int accNum;

public:
	AccountHandler();
	void AddAccount();

	BankAccount * findAcc(int ID);
	void depositMoney();
	int GetAccNum();
	void withdrawMoney();
	void ShowAllAccDeposits();
	~AccountHandler();
};