#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	bool isPrime(int);
	int m, n;
	cin >> m >> n;
	int *p = new int[n-m+1];

	for(int i = 0, num = 1; i <= n; num++)
	{
		if(isPrime(num))
		{
			i++;
			if(i-m >= 0) p[i-m] = num;
		}
	}

	for(int i = 0; i < n-m; i++)
	{
		cout << p[i];
		if((i+1)%10 != 0) cout << " ";
		else cout << endl;
	}
	cout << p[n-m];

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
