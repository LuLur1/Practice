#include <iostream>
using namespace std;

int main(void)
{
	cout<<"Press Enter key and your computer will shutdown after 10 seconds. \n";
	cout<<"Cancel Code : shutdown -a \n";
	getchar();
	system("@echo off");
	system("shutdown -s -t 10 -c \"Shutting down..\" ");
	return 0;
}
