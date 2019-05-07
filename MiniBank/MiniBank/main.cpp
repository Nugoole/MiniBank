#include "AccountHandler.cpp"

void ShowMenu(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main()
{

	AccountHandler<BnkPtr> *handler = new AccountHandler<BnkPtr>;
	int select;
	handler->LoadAccountFromFile();

	while (1) {
		rewind(stdin);
		ShowMenu();
		cin >> select;

		switch (select) {
		default:
			cout << "잘못된 선택 번호 입니다." << endl;
		case MAKE:
			if (handler->GetAccNum() > MAX_ACC_NUM)
			{
				cout << "더이상 계정을 만들 수 없습니다." << endl;
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

	system("cls");
	cout << "-----------Menu-------------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 전체출력" << endl;
	cout << "5. 종    료" << endl;
}