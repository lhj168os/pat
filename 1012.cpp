#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n, a1 = 0, a2 = 0, a2_flag = 0, a3 = 0, a4 = 0, a5 = 0;
	double A4 = 0;
	cin >> n;
	int *p = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for(int i = 0, x = 0; i < n; i++)
	{
		
		if(p[i]%2 == 0 && p[i]%5 == 0) a1 += p[i];
		if(p[i]%5 == 1) 
		{
			a2 += (p[i] * pow(-1, x));
			a2_flag = 1;
			x++;
		}
		if(p[i]%5 == 2) a3++;
		if(p[i]%5 == 3) 
		{
			a4++;
			A4 += p[i];
		}
		if(p[i]%5 == 4) a5 = p[i] > a5 ? p[i] : a5;
	}
	if(a1 != 0) cout << a1 << " ";
	else cout << "N" <<" ";
	
	if(a2_flag == 1) cout << a2 << " ";
	else cout << "N" << " ";

	if(a3 > 0) cout << a3 << " ";
	else cout << "N" << " ";

	if(a4 > 0) 
	{
		A4 /= a4;
		printf("%.1lf ", A4);
	}
	else cout << "N" << " ";
	
	if(a5 > 0) cout << a5;
	else cout << "N";

	return 0;
}
