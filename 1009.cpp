#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
	string str, word;
	getline(cin, str);
	vector<string> arr;
	istringstream ss(str);
	while(ss >> word)
	{
		arr.push_back(word);
	}

	cout << arr[arr.size()-1];
	for(int i = arr.size()-2; i >= 0; i--)
	{
		cout <<" "<< arr[i];
	}
	return 0;
}
