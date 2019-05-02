#pragma once
#include "MinibankingCommon.h"


class WithdrawException 
{
private:
	int withdrawMoney;

public:

	WithdrawException(int money) :withdrawMoney(money) {}

	void ShowExceptionMesg();
};

class NegativeMoneyInputException 
{
private:
	int inp_money;

public:
	NegativeMoneyInputException(int money) :inp_money(money) {}

	void ShowExceptionMesg();
};

class ArrFullException 
{
public:
	ArrFullException() {}

	void ShowExceptionMesg();
};

class AccNumException
{
private:
	int accNum;
public:
	AccNumException(int num) :accNum(num) {}

	void ShowExceptionMesg();
};