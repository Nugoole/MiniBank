#pragma once
#include "MinibankingCommon.h"

class Exceptions
{
public:
	virtual void ShowExceptionMesg() {};
};

class WithdrawException : public Exceptions
{
private:
	int withdrawMoney;

public:

	WithdrawException(int money) :withdrawMoney(money) {}

	void ShowExceptionMesg();
};

class NegativeMoneyInputException : public Exceptions
{
private:
	int inp_money;

public:
	NegativeMoneyInputException(int money) :inp_money(money) {}

	void ShowExceptionMesg();
};

class ArrFullException : public Exceptions
{
public:
	ArrFullException() {}

	void ShowExceptionMesg();
};

class AccNumException : public Exceptions
{
private:
	int accNum;
public:
	AccNumException(int num) :accNum(num) {}

	void ShowExceptionMesg();
};