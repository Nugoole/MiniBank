#include "Exceptions.h"

void WithdrawException::ShowExceptionMesg()
{
	cout << "��� �õ��� : " << withdrawMoney << endl;
	cout << "�ܾ��� �����մϴ�." << endl;
}

void NegativeMoneyInputException::ShowExceptionMesg()
{
	cout << "�Է��Ͻ� �ݾ� : " << inp_money << "��" << endl;
	cout << "��� ���� �Է����ּ���" << endl;
}

void ArrFullException::ShowExceptionMesg()
{
	cout << "�� �̻� ���¸� ������ �� �����ϴ�." << endl;
	cout << "���¼� �ִ� : " << MAX_ACC_NUM << "��" << endl;
}