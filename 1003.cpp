#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n, p_sum = 0, p_flag, t_sum = 0, t_flag, a1_sum, a2_sum, a3_sum;
	cin >> n;
	string *str = new string[n];
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	for(int i = 0; i < n; i++)
	{
		for(int k = 0; k < str[i].length(); k++)
		{
			if(str[i][k] != 'A' && str[i][k] != 'P' && str[i][k] != 'T')
			{
				str[i] = "NO";
				break;
			}
			else if(str[i][k] == 'P')
			{
				p_sum++;
				p_flag = k + 1;
			}
			else if(str[i][k] == 'T')
			{
				t_sum++;
				t_flag = k + 1;
			}
		}

		if(p_sum != 1 || t_sum != 1) str[i] = "NO";
		else if(t_flag - p_flag < 2) str[i] = "NO";
		else
		{
			a1_sum = p_flag - 1;
			a2_sum = t_flag - p_flag - 1;
			a3_sum = str[i].length() - t_flag;
			if(a1_sum * a2_sum == a3_sum) str[i] = "YES";
			else str[i] = "NO";
		}
		p_sum = 0;
		t_sum = 0;
	}


	for(int i = 0; i < n; i++)
	{
		cout << str[i] << endl;
	}
	return 0;
}
