/*
 * Programming Ability Test 
 *
 * Topic 1010 一元多项式求导
 * 题目：设计函数求一元多项式的导数。
 *（注：xn（n为整数）的一阶导数为n*xn-1。）
 * 输入格式：以指数递降方式输入多项式非零项系数和指数
 *（绝对值均为不超过1000的整数）。数字间以空格分隔。
 * 输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。
 * 数字间以空格分隔，但结尾不能有多余空格。
 * 注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
 * 
 * 输入样例：
 * 3 4 -5 2 6 1 -2 0
 * 输出样例：
 * 12 3 -10 1 6 0
 * 
 * Author：lhj
 * 2017.8.16
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> k;
	int x, flag = 0;
	while(1)
	{
		cin >> x;
		k.push_back(x);          //把输入的系数和指数存于向量k中
		if(cin.get() == '\n') break;    //行末结束输入
	}

	for(int i = 0; i < k.size()-1; i += 2)
	{
		if(k[i]*k[i+1] != 0)    //输出非零项
		{
			if(i > 0 && flag ==1) cout << " ";  
			cout << k[i]*k[i+1] << " " <<k[i+1]-1;
			flag = 1;
		}
	}
	if(flag == 0) cout << 0 << " " << 0;

	return 0;
}
