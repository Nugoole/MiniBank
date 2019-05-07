#include "AccountHandler.h"
#include <fstream>

template <typename T>
AccountHandler<T>::AccountHandler() :accNum(0) {
	acc = new T *[MAX_ACC_NUM];
}

template <typename T>
void AccountHandler<T>::LoadAccountFromFile() {

	ifstream file;
	int accType, deposits, accNo;
	String accName;
	int interest, original_depos;
	int accGrade;

	file.open("accountList.txt");

	if (file.fail())
	{
		cout << "���� ���⿡ �����߽��ϴ�." << endl;
	}
	else
	{
		do {
			file >> accType;

			cout << accType;

			//�Ϲ� ����
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

				acc[accNum] = new HighCreditAccount(accName, deposits, accNo, accGrade,original_depos,interest);
				accNum++;
			}
		} while (!file.eof());
		file.close();
	}
}

template <typename T>
void AccountHandler<T>::AddAccount()
{
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

				cout << "============���� ���� �Ϸ�==============" << endl;
				cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
				cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
				cout << "�����ָ� : " << acc[accNum]->GetAccName() << endl;

				accNum++;
				break;
			}
			catch (Exceptions& expt)
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

				cout << "============���� ���� �Ϸ�==============" << endl;
				cout << "���� ��ȣ : " << acc[accNum]->GetAccID() << endl;
				cout << "�ʱ� ���ݾ� :" << acc[accNum]->GetDeposits() << endl;
				cout << "�����ָ� : " << acc[accNum]->GetAccName() << endl;
				cout << "�ſ��� : " << acc[accNum]->getCreditLevel() << endl;

				accNum++;
				break;
			}
			catch (Exceptions& expt)
			{
				system("cls");
				expt.ShowExceptionMesg();
			}
		}
	}
}

template <typename T>
BankAccount& AccountHandler<T>::operator[](int idx)
{
	if (idx < 0 || idx >= accNum)
	{
		std::cout << "�ùٸ� �ε��� ���� �־��ּ���" << endl;
	}
	return *acc[idx];
}

template <typename T>
T AccountHandler<T>::findAcc(int ID) {
	if (accNum == 0) return NULL;

	for (int i = 0; i < accNum; i++)
		if (acc[i]->GetAccID() == ID)
			return acc[i];

	return NULL;
}


template <typename T>
void AccountHandler<T>::depositMoney()
{
	using std::cout;
	using std::cin;

	int ID, dep_money;
	cout << "�����Ͻ� ���¹�ȣ�� �Է����ּ���";
	cin >> ID;

	T * temp = findAcc(ID);
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
		catch (Exceptions& expt)
		{
			system("cls");
			expt.ShowExceptionMesg();
		}
	}

	cout << "=============���� �Ϸ�=================" << endl;
	cout << "���� �� �ܾ� : " << temp->GetDeposits() << endl;
}


template <typename T>
void AccountHandler<T>::withdrawMoney()
{
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
		catch (Exceptions& expt)
		{
			system("cls");
			expt.ShowExceptionMesg();
		}
	}
}

template <typename T>
int AccountHandler<T>::GetAccNum()
{
	return accNum;
}

template <typename T>
void AccountHandler<T>::ShowAllAccDeposits()
{
	for (int i = 0; i < accNum; i++)
	{
		if (acc[i]->getCreditLevel() == 'D')
			cout << "<===== �Ϲ� �� =====>" << endl;
		else
		{
			cout << "<===== �ſ� �� =====>" << endl;
			cout << "�� ��� : " << acc[i]->getCreditLevel() << endl;
		}

		cout << acc[i]->GetAccName() << " ���� ";
		acc[i]->printDeposits();
		acc[i]->printNowRoI();
		cout << endl;
	}
}

template <typename T>
AccountHandler<T>::~AccountHandler()
{
	ofstream outFile;
	outFile.open("accountList.txt", ofstream::in | ofstream::out| ofstream::trunc);

	for (int i = 0; i < accNum; i++)
	{
		if (acc[i]->getCreditLevel() != 'D')
		{
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