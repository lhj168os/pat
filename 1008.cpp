#include <iostream>

using namespace std;

int main()
{
	int n, m, swp;
	cin >> n >> m;
	int *a = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < m; i++)
	{
		swp = a[n-1];
		for(int k = n-1; k >= 0; k--)
		{
			a[k] = a[k-1];
		}
		a[0] = swp;
	}
	cout << a[0];
	for(int i = 1; i < n; i++)
	{
		cout << " " << a[i];
	}
	return 0;
}
