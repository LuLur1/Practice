#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

int main(void)
{
	cout<<"\"�� Windows�� ��ǰ�� �ƴմϴ�. \" ��� �޼����� �߻��Ͽ��� �� �����մϴ�. \n";
	cout<<"EnterŰ�� ������ ������ �����մϴ�. \n";
	getchar();
	system("slmgr -rearm");
	
	return 0;
}
