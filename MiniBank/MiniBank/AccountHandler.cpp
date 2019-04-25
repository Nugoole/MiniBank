#include "AccountHandler.h"


AccountHandler::AccountHandler() :accNum(0) {}


void AccountHandler::AddAccount()
{
	int select;

	cout << "� ������ ���¸� �����Ͻðڽ��ϱ�?" << endl;
	cout << "[1. ���뿹�ݰ���    2. �ſ�ŷڰ���]" << endl;
	cin >> select;


	if (select == NORMAL)
	{
		int AccountNum, deposit;
		char * name;
		name = new char[30];

		cout << "���� ��ȣ�� �������ּ���";
		cin >> AccountNum;
		cout << "�����Ͻ� �ݾ��� �Է����ּ���";
		cin >> deposit;
		cout << "������ �̸��� �Է����ּ���";
		cin >> name;

		NormalAccount * temp = new NormalAccount(name, deposit, AccountNum);
		acc[accNum] = (BankAccount *)temp;

		cout << "============���� ���� �Ϸ�==============" << endl;
		cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
		cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
		cout << "�����ָ� : " << acc[accNum]->GetAccName() << endl;

		accNum++;
	}
	else if (select == CREDIT)
	{
		int AccountNum, deposit, RoI;
		char credit_level;
		char * name;

		cout << "���� ��ȣ�� �������ּ���";
		cin >> AccountNum;
		cout << "�����Ͻ� �ݾ��� �Է����ּ���";
		cin >> deposit;
		cout << "������ �̸��� �Է����ּ���";
		cin >> name;
		cout << "���� �ſ����� ����ּ���" << endl;
		cout << "[��� ��� : A    B    C ]";
		cin >> credit_level;

		if (credit_level == 'A' || credit_level == 'a')
			RoI = LEVEL_A;
		else if (credit_level == 'B' || credit_level == 'b')
			credit_level = LEVEL_B;
		else if (credit_level == 'C' || credit_level == 'c')
			credit_level = LEVEL_C;



		acc[accNum] = new HighCreditAccount(name, deposit, AccountNum, RoI);

		cout << "============���� ���� �Ϸ�==============" << endl;
		cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
		cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
		cout << "�����ָ� : " << acc[accNum]->GetAccName() << endl;
		cout << "�ſ��� : " << acc[accNum]->getCreditLevel() << endl;
	}
}


BankAccount * AccountHandler::findAcc(int ID) {
	for (int i = 0; i < accNum; i++)
		if (acc[i]->GetAccID() == ID)
			return acc[i];

	return NULL;
}


void AccountHandler::depositMoney()
{
	int ID, dep_money;
	cout << "�����Ͻ� ���¹�ȣ�� �Է����ּ���";
	cin >> ID;

	BankAccount * temp = findAcc(ID);
	if (temp == NULL)
	{
		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}

	cout << "�����Ͻ� �ݾ��� �Է����ּ���. ";
	cin >> dep_money;
	temp->DepositsMoney(dep_money);

	cout << "=============���� �Ϸ�=================" << endl;
	cout << "���� �� �ܾ� : " << temp->GetDeposits() << endl;
}

void AccountHandler::withdrawMoney()
{
	int ID, with_money;
	cout << "�����Ͻ� ���¹�ȣ�� �Է����ּ���";
	cin >> ID;

	BankAccount * temp = findAcc(ID);
	if (temp == NULL)
	{
		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}

	cout << "�����Ͻ� �ݾ��� �Է����ּ���. ";
	cin >> with_money;
	if (temp->GetDeposits() < with_money)
	{
		cout << "�ܾ��� �����մϴ�." << endl;
		return;
	}

	temp->DepositsMoney(with_money);

	cout << "=============���� �Ϸ�=================" << endl;
	cout << "���� �� �ܾ� : " << temp->GetDeposits() << endl;
}

int AccountHandler::GetAccNum()
{
	return accNum;
}

void AccountHandler::ShowAllAccDeposits()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << acc[i]->GetAccName() << " ���� ";
		acc[i]->printDeposits();
	}
}


AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete acc[i];
}