#include "AccountHandler.h"

void ShowMenu(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main()
{
	using std::cout;
	using std::cin;

	AccountHandler *handler = new AccountHandler;
	int select;

	while (1) {
		rewind(stdin);
		ShowMenu();
		cin >> select;

		switch (select) {
		default:
			cout << "�߸��� ���� ��ȣ �Դϴ�." << endl;
		case MAKE:
			if (handler->GetAccNum() > MAX_ACC_NUM)
			{
				cout << "���̻� ������ ���� �� �����ϴ�." << endl;
				break;
			}
			handler->AddAccount();
			break;
		case DEPOSIT:
			handler->depositMoney();
			break;
		case WITHDRAW:
			handler->withdrawMoney();
			break;
		case INQUIRE:
			handler->ShowAllAccDeposits();
			break;
		case EXIT:
			delete handler;
			return 0;
		}

		cin.get();
		cin.get();
	}
}

void ShowMenu(void) {
	using std::cout;
	using std::cin;

	system("cls");
	cout << "-----------Menu-------------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ��ü���" << endl;
	cout << "5. ��    ��" << endl;
}