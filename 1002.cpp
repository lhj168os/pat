/* PAT Test
 * Topic 1002
 * Author: lhj
 * Date: 2017.8.16
 *
 * 读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
 * 输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。 * 输出格式：在一行内输出n的各位数字之和的每一位，
 * 拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
 *
 * 输入样例：
 * 1234567890987654321123456789
 * 输出样例：
 * yi san wu
 */
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int swp, sum = 0;
	string n, str_swp, str_sum;
	cin>>n;

	for(int i = 0; i < n.length(); i++){
		str_swp = n[i];
		stringstream str_stream(str_swp);
		str_stream >> swp;
		sum += swp;
	}
	ostringstream int_stream;
	int_stream << sum;
	str_sum = int_stream.str();

	for(int j = 0; j < str_sum.length(); j++){
		switch(str_sum[j]){
			case '1': cout<<"yi";break;
			case '2': cout<<"er";break;
			case '3': cout<<"san";break;
			case '4': cout<<"si";break;	
			case '5': cout<<"wu";break;	
			case '6': cout<<"liu";break;	
			case '7': cout<<"qi";break;	
			case '8': cout<<"ba";break;	
			case '9': cout<<"jiu";break;	
			case '0': cout<<"ling";break;
		}
		if(j < (str_sum.length() - 1))cout<<" ";
	}
	return 0;
}
