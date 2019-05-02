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

	cout << "� ������ ���¸� �����Ͻðڽ��ϱ�?" << endl;
	cout << "[1. ���뿹�ݰ���    2. �ſ�ŷڰ���]" << endl;
	cin >> select;


	if (select == NORMAL)
	{
		while (1) {
			try {
				int AccountNum, deposit;
				String name;

				if (accNum >= MAX_ACC_NUM)
					throw ArrFullException();

				

				cout << "���� ��ȣ�� �������ּ���";
				cin >> AccountNum;
				cout << "�����Ͻ� �ݾ��� �Է����ּ���";
				cin >> deposit;
				rewind(stdin);
				cout << "������ �̸��� �Է����ּ���";
				str::cin >> name;

				if (findAcc(AccountNum) != NULL)
					throw AccNumException(AccountNum);

				acc[accNum] = new NormalAccount(name, deposit, AccountNum);

				cout << "============���� ���� �Ϸ�==============" << endl;
				cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
				cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
				str::cout << "�����ָ� : " << acc[accNum]->GetAccName() << str::endl;

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

				cout << "���� ��ȣ�� �������ּ���";
				cin >> AccountNum;
				cout << "�����Ͻ� �ݾ��� �Է����ּ���";
				cin >> deposit;
				rewind(stdin);
				cout << "������ �̸��� �Է����ּ���";
				str::cin >> name;
				cout << "���� �ſ����� ����ּ���" << endl;
				cout << "[��� ��� : A    B    C ]";
				cin >> credit_level;

				if (credit_level == 'A' || credit_level == 'a')
					RoI = LEVEL_A;
				else if (credit_level == 'B' || credit_level == 'b')
					RoI = LEVEL_B;
				else if (credit_level == 'C' || credit_level == 'c')
					RoI = LEVEL_C;

				cout << RoI << endl;

				if (findAcc(AccountNum) != NULL)
					throw AccNumException(AccountNum);

				acc[accNum] = new HighCreditAccount(name, deposit, AccountNum, RoI);

				cout << "============���� ���� �Ϸ�==============" << endl;
				cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
				cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
				str::cout << "�����ָ� : " << acc[accNum]->GetAccName() << str::endl;
				cout << "�ſ��� : " << acc[accNum]->getCreditLevel() << endl;

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
		std::cout << "�ùٸ� �ε��� ���� �־��ּ���" << endl;
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
	cout << "�����Ͻ� ���¹�ȣ�� �Է����ּ���";
	cin >> ID;

	BankAccount * temp = findAcc(ID);
	if (temp == NULL)
	{
		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}
	while (1) {
		cout << "�����Ͻ� �ݾ��� �Է����ּ���. ";
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

	cout << "=============���� �Ϸ�=================" << endl;
	cout << "���� �� �ܾ� : " << temp->GetDeposits() << endl;
}

void AccountHandler::withdrawMoney()
{
	using std::cout;
	using std::cin;

	int ID, with_money;
	cout << "����Ͻ� ���¹�ȣ�� �Է����ּ���";
	cin >> ID;

	BankAccount * temp = findAcc(ID);
	if (temp == NULL)
	{
		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}

	while (1) {
		cout << "����Ͻ� �ݾ��� �Է����ּ���. ";
		cin >> with_money;
		try {
			temp->withdrawMoney(with_money);

			cout << "=============��� �Ϸ�=================" << endl;
			cout << "��� �� �ܾ� : " << temp->GetDeposits() << endl;
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
		str::cout << acc[i]->GetAccName() << " ���� ";
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