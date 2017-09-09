#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	bool isPrime(int);
	int num, sum = 0;
	cin >> num;
	for(int i = num; i >= 5; i--)
	{
		if(isPrime(i) && isPrime(i-2)) sum++;
	}
	cout << sum;
	return 0;
}

bool isPrime(int num)
{
	int tmp = sqrt(num);
	if(num == 1) return false;
	if(num == 2 || num == 3) return true;
	if(num%6 != 1 && num%6 != 5) return false;
	for(int i = 5; i <= tmp; i+=6)
	{
		if(num%i == 0 || num%(i+2) == 0) return false;
	}
	return true;
}
