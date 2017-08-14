#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	bool compares(const deque<int> &n, const deque<int> &m);
	int judgeClz(deque<int>, deque<int>);
	deque<int> clzColl(int);
	int n;
	cin >> n;
	deque<deque<int>> keyColl;
	vector<int> keyNum;
	int *ary = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
		keyColl.push_front(clzColl(ary[i]));
	}

	sort(keyColl.begin(), keyColl.end(), compares);   //keyColl按元素长度排序

	for (size_t i = 0; i < keyColl.size(); i++)
	{		
		for (size_t k = i + 1; k < keyColl.size(); k++)
		{
			if (judgeClz(keyColl[i], keyColl[k]) == 1)
			{
				keyColl.erase(keyColl.begin() + k);
				k--;
				continue;
			}
			if (judgeClz(keyColl[i], keyColl[k]) == 2)
			{
				keyColl.erase(keyColl.begin() + i);
				k--;
				continue;
			}
			
		}
	}

	for (size_t i = 0; i < keyColl.size(); i++)
	{
		keyNum.push_back(keyColl[i][keyColl[i].size() - 1]);
	}

	sort(keyNum.begin(), keyNum.end());

	cout << keyNum[keyNum.size() - 1];
	for (int i = keyNum.size() - 2; i >= 0; i--)
	{
		cout << " " << keyNum[i];
	}
	return 0;
}

int judgeClz(deque<int> n, deque<int> m)
{
	int i = n.size(), j = m.size();
	if (i > j && n[j - 1] == m[j - 1])
	{
		return 1;
	}
	else if(i <= j && n[i - 1] == m[i - 1])
	{
		return 2;
	}
	return 0;
}

deque<int> clzColl(int n)
{
	deque<int> m;
	m.push_front(n);
	if (n == 1) {
		return m;
	}
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			m.push_front(n);
		}
		else {
			n = (3 * n + 1) / 2;
			m.push_front(n);
		}
	}
	return m;
}

bool compares(const deque<int> &n, const deque<int> &m)
{
	return n.size() > m.size();
}