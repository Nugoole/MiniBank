#include "AccountHandler.h"
#include <fstream>

//TODO : 파일 마지막에 입력할 때 이자 돈을 기본액에 추가해서 저장하기
AccountHandler::AccountHandler() :accNum(0) {
	acc = new BankAccount *[MAX_ACC_NUM];
}

void AccountHandler::LoadAccountFromFile() {
	ifstream file;
	int accType, deposits, accNo;
	String accName;
	int interest, original_depos;
	int accGrade;

	file.open("accountList.txt");

	if (file.fail())
	{
		cout << "파일 열기에 실패했습니다." << endl;
		getchar();
	}
	else
	{
		do {
			file >> accType;

			cout << accType;
			getchar();
			//일반 계좌
			if (accType == 1)
			{
				file >> accName
					>> deposits
					>> interest
					>> accNo;

				cout << accName
					<< deposits
					<< interest
					<< accNo;
				getchar();
				acc[accNum] = new NormalAccount(accName, deposits, accNo,interest);
				accNum++;
			}
			else if (accType == 2)
			{
				file >> accName
					>> deposits
					>> accNo
					>> interest
					>> original_depos
					>> accGrade;
				cout << accName
					<< deposits
					<< interest
					<< accNo
					<< accGrade;

				if (accGrade == 1)
					accGrade = LEVEL_A;
				else if (accGrade == 2)
					accGrade = LEVEL_B;
				else if (accGrade == 3)
					accGrade = LEVEL_C;

				getchar();
				acc[accNum] = new HighCreditAccount(accName, deposits, accNo, accGrade,original_depos,interest);
				accNum++;
			}
		} while (!file.eof());
		file.close();
	}
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
		while (1) {
			try {
				int AccountNum, deposit;
				String name;

				if (accNum >= MAX_ACC_NUM)
					throw ArrFullException();

				

				cout << "계좌 번호를 설정해주세요";
				cin >> AccountNum;
				cout << "예금하실 금액을 입력해주세요";
				cin >> deposit;
				rewind(stdin);
				cout << "예금주 이름을 입력해주세요";
				cin >> name;

				if (findAcc(AccountNum) != NULL)
					throw AccNumException(AccountNum);

				acc[accNum] = new NormalAccount(name, deposit, AccountNum);
				cout << sizeof(*acc[accNum]);
				cout << "============계좌 개설 완료==============" << endl;
				cout << "계좌 번호 : " << acc[accNum]->GetAccID() << endl;
				cout << "초기 예금액 :" << acc[accNum]->GetDeposits() << endl;
				cout << "예금주명 : " << acc[accNum]->GetAccName() << endl;

				accNum++;
				break;
			}
			catch (AccNumException& expt)
			{
				system("cls");
				expt.ShowExceptionMesg();
			}
			catch (ArrFullException& expt)
			{
				system("cls");
				expt.ShowExceptionMesg();
			}
			catch (NegativeMoneyInputException& expt)
			{
				system("cls");
				expt.ShowExceptionMesg();
			}
		}
	}
	else if (select == CREDIT)
	{
		while (1) {
			try {
				int AccountNum, deposit, RoI;
				char credit_level;
				String name;

				if (accNum >= MAX_ACC_NUM)
					throw ArrFullException();

				cout << "계좌 번호를 설정해주세요";
				cin >> AccountNum;
				cout << "예금하실 금액을 입력해주세요";
				cin >> deposit;
				rewind(stdin);
				cout << "예금주 이름을 입력해주세요";
				cin >> name;
				cout << "현재 신용등급을 골라주세요" << endl;
				cout << "[등급 목록 : A    B    C ]";
				cin >> credit_level;

				if (credit_level == 'A' || credit_level == 'a')
					RoI = LEVEL_A;
				else if (credit_level == 'B' || credit_level == 'b')
					RoI = LEVEL_B;
				else if (credit_level == 'C' || credit_level == 'c')
					RoI = LEVEL_C;

				if (findAcc(AccountNum) != NULL)
					throw AccNumException(AccountNum);

				acc[accNum] = new HighCreditAccount(name, deposit, AccountNum, RoI);
				cout << sizeof(*acc[accNum]);

				cout << "============계좌 개설 완료==============" << endl;
				cout << "계좌 번호 : " << acc[accNum]->GetAccID() << endl;
				cout << "초기 예금액 :" << acc[accNum]->GetDeposits() << endl;
				cout << "예금주명 : " << acc[accNum]->GetAccName() << endl;
				cout << "신용등급 : " << acc[accNum]->getCreditLevel() << endl;

				accNum++;
				break;
			}
			catch (AccNumException& expt)
			{
				system("cls");
				expt.ShowExceptionMesg();
			}
			catch (ArrFullException& expt)
			{
				system("cls");
				expt.ShowExceptionMesg();
			}
			catch (NegativeMoneyInputException& expt)
			{
				system("cls");
				expt.ShowExceptionMesg();
			}
		}
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
	if (accNum == 0) return NULL;

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
	while (1) {
		cout << "예금하실 금액을 입력해주세요. ";
		cin >> dep_money;
		try {
			temp->DepositsMoney(dep_money);
			break;
		}
		catch (NegativeMoneyInputException& expt)
		{
			system("cls");
			expt.ShowExceptionMesg();
		}
	}

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

	while (1) {
		cout << "출금하실 금액을 입력해주세요. ";
		cin >> with_money;
		try {
			temp->withdrawMoney(with_money);

			cout << "=============출금 완료=================" << endl;
			cout << "출금 후 잔액 : " << temp->GetDeposits() << endl;
			break;
		}
		catch (WithdrawException& expt)
		{
			system("cls");
			expt.ShowExceptionMesg();
		}
		catch (NegativeMoneyInputException& expt) {
			system("cls");
			expt.ShowExceptionMesg();
		}
	}
}

int AccountHandler::GetAccNum()
{
	return accNum;
}

void AccountHandler::ShowAllAccDeposits()
{
	for (int i = 0; i < accNum; i++)
	{
		if (acc[i]->getCreditLevel() == 'D')
			cout << "<===== 일반 고객 =====>" << endl;
		else
		{
			cout << "<===== 신용 고객 =====>" << endl;
			cout << "고객 등급 : " << acc[i]->getCreditLevel() << endl;
		}
		cout << acc[i]->GetAccName() << " 님의 ";
		acc[i]->printDeposits();
		acc[i]->printNowRoI();
		cout << endl;
	}
}


AccountHandler::~AccountHandler()
{
	ofstream outFile;
	outFile.open("accountList.txt", ofstream::in | ofstream::out| ofstream::trunc);

	for (int i = 0; i < accNum; i++)
	{

		if (acc[i]->getCreditLevel() != 'D')
		{
			cout << acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->GetAccID() << '\t'
				<< acc[i]->getInterest() << '\t'
				<< acc[i]->getFirstDepos() << '\t'
				<< ((int)acc[i]->getCreditLevel() - 64) << '\n';

			outFile << 2 << '\t'
				<< acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->GetAccID() << '\t'
				<< acc[i]->getInterest() << '\t'
				<< acc[i]->getFirstDepos() << '\t'
				<< ((int)acc[i]->getCreditLevel() - 64);
		}
		else
		{
			cout << acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->GetAccID() << '\n';

			outFile << 1 << '\t'
				<< acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->getInterest() << '\t'
				<< acc[i]->GetAccID();
		}
		if (i != accNum - 1)
			outFile << '\n';
		delete acc[i];
	}
	outFile.close();
	delete[] acc;
}