#include "AccountHandler.h"
#include <fstream>

//TODO : ���� �������� �Է��� �� ���� ���� �⺻�׿� �߰��ؼ� �����ϱ�
AccountHandler::AccountHandler() :accNum(0) {
	acc = new BankAccount *[MAX_ACC_NUM];
}

void AccountHandler::LoadAccountFromFile() {
	ifstream file;
	int accType, deposits, accNo;
	String accName;
	int accGrade;

	file.open("C:/Users/jundo/source/repos/MiniBank/MiniBank/MiniBank/accountList.txt");

	if (file.fail())
	{
		cout << "���� ���⿡ �����߽��ϴ�." << endl;
		getchar();
	}
	else
	{
		do {
			file >> accType;

			cout << accType;
			getchar();
			//�Ϲ� ����
			if (accType == 1)
			{
				file >> accName
					>> deposits
					>> accNo;

				cout << accName
					<< deposits
					<< accNo;
				getchar();
				acc[accNum] = new NormalAccount(accName, deposits, accNo);
				accNum++;
			}
			else if (accType == 2)
			{
				file >> accName
					>> deposits
					>> accNo
					>> accGrade;
				cout << accName
					<< deposits
					<< accNo
					<< accGrade;

				getchar();
				acc[accNum] = new HighCreditAccount(accName, deposits, accNo, accGrade);
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
				cin >> name;

				if (findAcc(AccountNum) != NULL)
					throw AccNumException(AccountNum);

				acc[accNum] = new NormalAccount(name, deposit, AccountNum);
				cout << sizeof(*acc[accNum]);
				cout << "============���� ���� �Ϸ�==============" << endl;
				cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
				cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
				cout << "�����ָ� : " << acc[accNum]->GetAccName() << endl;

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
				cin >> name;
				cout << "���� �ſ����� ����ּ���" << endl;
				cout << "[��� ��� : A    B    C ]";
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

				cout << "============���� ���� �Ϸ�==============" << endl;
				cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
				cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
				cout << "�����ָ� : " << acc[accNum]->GetAccName() << endl;
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
		cout << acc[i]->GetAccName() << " ���� ";
		acc[i]->printDeposits();
		acc[i]->printNowRoI();
	}
}


AccountHandler::~AccountHandler()
{
	ofstream outFile;
	outFile.open("accountList.txt", ofstream::in | ofstream::trunc);

	for (int i = 0; i < accNum; i++)
	{

		if (acc[i]->getCreditLevel() != 'D')
		{
			cout << acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->GetAccID() << '\t'
				<< (int)((int)acc[i]->getCreditLevel() - 64) << '\n';

			outFile << 2 << '\t'
				<< acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->GetAccID() << '\t'
				<< (int)((int)acc[i]->getCreditLevel() - 64);
		}
		else
		{
			cout << acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->GetAccID() << '\t'
				<< acc[i]->getCreditLevel() << '\n';

			outFile << 1 << '\t'
				<< acc[i]->GetAccName() << '\t'
				<< acc[i]->GetDeposits() << '\t'
				<< acc[i]->GetAccID();
		}
		if (i != accNum - 1)
			outFile << '\n';
		delete acc[i];
	}
	outFile.close();
	delete[] acc;
}