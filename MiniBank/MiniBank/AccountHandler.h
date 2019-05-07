#pragma once
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Exceptions.h"



template <typename T>
class AccountHandler
{
private:
	T** acc;
	int accNum;

public:


	AccountHandler();
	void AddAccount();
	void LoadAccountFromFile();

	T& operator[](int idx);

	T* findAcc(int ID);
	void depositMoney();
	int GetAccNum();
	void withdrawMoney();
	void ShowAllAccDeposits();
	~AccountHandler();
};