#pragma once
#include "MinibankingCommon.h"
#include "String_make.h"
#include "Exceptions.h"



class BankAccount
{
private:	
	String name;
	int deposits;
	int AccountNum;
	

public:
	BankAccount(const String name = "ȫ�浿", int money = 0, int ID = 0);
	int GetDeposits() const;
	virtual void DepositsMoney(int val);
	void withdrawMoney(int val);
	int GetAccID();
	String& GetAccName();
	void printDeposits() const;

	virtual int getFirstDepos() = 0;
	virtual int  getInterest() = 0;
	virtual void printNowRoI() const = 0;
	virtual char getCreditLevel() const = 0;

	~BankAccount();
	
};