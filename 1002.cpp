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
