#include "AccountHandler.h"


AccountHandler::AccountHandler() :accNum(0) {
	acc = new BankAccount *[MAX_ACC_NUM];
}

void AccountHandler::AddAccount()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int select;

	cout << "어떤 유형의 계좌를 개설하시겠습니까?" << endl;
	cout << "[1. 보통예금계좌    2. 신용신뢰계좌]" << endl;
	cin >> select;


	if (select == NORMAL)
	{
		int AccountNum, deposit;
		char * name;
		name = new char[30];

		cout << "계좌 번호를 설정해주세요";
		cin >> AccountNum;
		cout << "예금하실 금액을 입력해주세요";
		cin >> deposit;
		cout << "예금주 이름을 입력해주세요";
		cin >> name;

		acc[accNum] = new NormalAccount(name, deposit, AccountNum);

		cout << "============계좌 개설 완료==============" << endl;
		cout << "계좌 번호 : " << acc[accNum]->GetAccID() << endl;
		cout << "초기 예금액 :" << acc[accNum]->GetDeposits() << endl;
		str::cout << "예금주명 : " << acc[accNum]->GetAccName() << str::endl;

		accNum++;
	}
	else if (select == CREDIT)
	{
		int AccountNum, deposit, RoI;
		char credit_level;
		String name;
		name = new char[30];
		cout << "계좌 번호를 설정해주세요";
		cin >> AccountNum;
		cout << "예금하실 금액을 입력해주세요";
		cin >> deposit;
		cout << "예금주 이름을 입력해주세요";
		str::cin >> name;
		cout << "현재 신용등급을 골라주세요" << endl;
		cout << "[등급 목록 : A    B    C ]";
		cin >> credit_level;

		if (credit_level == 'A' || credit_level == 'a')
			RoI = LEVEL_A;
		else if (credit_level == 'B' || credit_level == 'b')
			RoI = LEVEL_B;
		else if (credit_level == 'C' || credit_level == 'c')
			RoI = LEVEL_C;

		cout << RoI << endl;

		acc[accNum] = new HighCreditAccount(name, deposit, AccountNum, RoI);

		cout << "============계좌 개설 완료==============" << endl;
		cout << "계좌 번호 : " << acc[accNum]->GetAccID() << endl;
		cout << "초기 예금액 :" << acc[accNum]->GetDeposits() << endl;
		str::cout << "예금주명 : " << acc[accNum]->GetAccName() << str::endl;
		cout << "신용등급 : " << acc[accNum]->getCreditLevel() << endl;

		accNum++;
	}
}

BankAccount& AccountHandler::operator[](int idx)
{
	if (idx < 0 || idx >= accNum)
	{
		std::cout << "올바른 인덱스 값을 넣어주세요" << endl;
	}
	return *acc[idx];
}


BankAccount * AccountHandler::findAcc(int ID) {
	for (int i = 0; i < accNum; i++)
		if (acc[i]->GetAccID() == ID)
			return acc[i];

	return NULL;
}


void AccountHandler::depositMoney()
{
	using std::cout;
	using std::cin;

	int ID, dep_money;
	cout << "예금하실 계좌번호를 입력해주세요";
	cin >> ID;

	BankAccount * temp = findAcc(ID);
	if (temp == NULL)
	{
		cout << "존재하지 않는 계좌입니다." << endl;
		return;
	}

	cout << "예금하실 금액을 입력해주세요. ";
	cin >> dep_money;
	temp->DepositsMoney(dep_money);

	cout << "=============예금 완료=================" << endl;
	cout << "예금 후 잔액 : " << temp->GetDeposits() << endl;
}

void AccountHandler::withdrawMoney()
{
	using std::cout;
	using std::cin;

	int ID, with_money;
	cout << "출금하실 계좌번호를 입력해주세요";
	cin >> ID;

	BankAccount * temp = findAcc(ID);
	if (temp == NULL)
	{
		cout << "존재하지 않는 계좌입니다." << endl;
		return;
	}

	cout << "출금하실 금액을 입력해주세요. ";
	cin >> with_money;
	if (temp->GetDeposits() < with_money)
	{
		cout << "잔액이 부족합니다." << endl;
		return;
	}

	temp->withdrawMoney(with_money);

	cout << "=============출금 완료=================" << endl;
	cout << "출금 후 잔액 : " << temp->GetDeposits() << endl;
}

int AccountHandler::GetAccNum()
{
	return accNum;
}

void AccountHandler::ShowAllAccDeposits()
{
	for (int i = 0; i < accNum; i++)
	{
		str::cout << acc[i]->GetAccName() << " 님의 ";
		acc[i]->printDeposits();
		acc[i]->printNowRoI();
	}
}


AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete acc[i];

	delete[] acc;
}