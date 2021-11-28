#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int sink[12] = { 2,2,2,2,2,2,2,2,2,2,2,2 };
int weight[2] = { -1, 1 };

int main(void)
{
	int left, right;
	int num;
	int leftSide;
	int rightSide;
	int answer;

	srand((unsigned)time(NULL));
	int sink_select = rand() % 12;
	int weight_select = rand() % 2;
	sink[sink_select] += weight[weight_select];

	cout << "������ �߰� �����Ǿ����ϴ�." << endl;
	cout << "===== ���� �̸����� =====" << endl;

	for (int i = 0; i < 12; i++)
	{
		cout << sink[i] << " ";
	}
	
	cout << endl;
	
	for (int stage = 1; stage <= 3; stage++)
	{
		rightSide = 0;
		leftSide = 0;

		cout << "���� ���Ը� �� ���� �� �������ּ���(���� ����) >> ";
		cin >> left;

		cout << "���� ���Ը� �� �߸� �������ּ���." << endl;
		for (int i = 0; i < left; i++)
		{
			cout << "���� " << i + 1 << "��° �� >> ";
			cin >> num;

			leftSide += sink[num - 1];
		}

		cout << "������ ���Ը� �� ���� �� �������ּ���(���� ����) >> ";
		cin >> right;

		cout << "������ ���Ը� �� �߸� �������ּ���." << endl;
		for (int i = 0; i < right; i++)
		{
			cout << "������ " << i + 1 << "��° �� >> ";
			cin >> num;

			rightSide += sink[num - 1];
		}

		cout << endl << "��� : ";

		if (leftSide > rightSide)
			cout << "�������� ������!" << endl;

		else if (leftSide < rightSide)
			cout << "���������� ������!" << endl;

		else cout << "���Ծ���!" << endl;

		Sleep(3000);
		system("cls");
	}

	while (1)
	{
		cout << "���� �߸� ����ּ��� >> ";
		cin >> answer;

		if (sink[answer - 1] != 2)
		{
			cout << "�����Դϴ�!" << endl;
			return 0;
		}

		else cout << "�����Դϴ�!" << endl;
	}
}