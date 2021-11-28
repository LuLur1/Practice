#include <iostream>
using namespace std;

int main(void)
{
	cout << "Delete path : C:\\Users\\admin\\AppData\\Local\\Temp \n";
	cout << "Press Enter Key and Start to Delete...";
	getchar();
	system("rmdir C:\\Users\\admin\\AppData\\Local\\Temp /s /q");
	cout << "\n \nPress Enter to Close..";
	getchar();
	return 0;
}