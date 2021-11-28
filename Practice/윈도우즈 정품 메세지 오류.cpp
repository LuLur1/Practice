#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

int main(void)
{
	cout<<"\"이 Windows는 정품이 아닙니다. \" 라는 메세지가 발생하였을 때 실행합니다. \n";
	cout<<"Enter키를 누르면 오류를 수정합니다. \n";
	getchar();
	system("slmgr -rearm");
	
	return 0;
}
