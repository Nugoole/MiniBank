#include "Exceptions.h"

void WithdrawException::ShowExceptionMesg()
{
	cout << "출금 시도액 : " << withdrawMoney << endl;
	cout << "잔액이 부족합니다." << endl;
}

void NegativeMoneyInputException::ShowExceptionMesg()
{
	cout << "입력하신 금액 : " << inp_money << "원" << endl;
	cout << "양수 값을 입력해주세요" << endl;
}

void ArrFullException::ShowExceptionMesg()
{
	cout << "더 이상 계좌를 생성할 수 없습니다." << endl;
	cout << "계좌수 최댓값 : " << MAX_ACC_NUM << "개" << endl;
}