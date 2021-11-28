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

	cout << "랜덤한 추가 결정되었습니다." << endl;
	cout << "===== 정답 미리보기 =====" << endl;

	for (int i = 0; i < 12; i++)
	{
		cout << sink[i] << " ";
	}
	
	cout << endl;
	
	for (int stage = 1; stage <= 3; stage++)
	{
		rightSide = 0;
		leftSide = 0;

		cout << "왼쪽 무게를 잴 추의 수 결정해주세요(추의 개수) >> ";
		cin >> left;

		cout << "왼쪽 무게를 잴 추를 결정해주세요." << endl;
		for (int i = 0; i < left; i++)
		{
			cout << "왼쪽 " << i + 1 << "번째 추 >> ";
			cin >> num;

			leftSide += sink[num - 1];
		}

		cout << "오른쪽 무게를 잴 추의 수 결정해주세요(추의 개수) >> ";
		cin >> right;

		cout << "오른쪽 무게를 잴 추를 결정해주세요." << endl;
		for (int i = 0; i < right; i++)
		{
			cout << "오른쪽 " << i + 1 << "번째 추 >> ";
			cin >> num;

			rightSide += sink[num - 1];
		}

		cout << endl << "결과 : ";

		if (leftSide > rightSide)
			cout << "왼쪽으로 기울었다!" << endl;

		else if (leftSide < rightSide)
			cout << "오른쪽으로 기울었다!" << endl;

		else cout << "변함없다!" << endl;

		Sleep(3000);
		system("cls");
	}

	while (1)
	{
		cout << "정답 추를 골라주세요 >> ";
		cin >> answer;

		if (sink[answer - 1] != 2)
		{
			cout << "정답입니다!" << endl;
			return 0;
		}

		else cout << "오답입니다!" << endl;
	}
}
