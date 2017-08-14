#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int num;
	cin >> num;
	if(num > 0 && num <100)
	{
		for(int i = num/10; i > 0; i--)
		{
			cout << "S";
		}
		for(int i = 1; i <= num%10; i++)
		{
			cout << i;
		}
	}
	else if(num > 99 && num < 1000)
	{
		for(int i = num/100; i > 0; i--)
		{
			cout << "B";
		}
		for(int i = (num/10)%10; i > 0; i--)
		{
			cout << "S";
		}
		for(int i = 1; i <= num%10; i++)
		{
			cout << i;
		}
	}
	else cout << "input error!";
	return 0;
}
