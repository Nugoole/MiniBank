#pragma once
#include "NormalAccount.h"
#include "HighCreditAccount.h"

const int MAX_ACC_NUM = 100;
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
	void withdrawMoney();
	void ShowAllAccDeposits();
	~AccountHandler();
};