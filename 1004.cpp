#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student();
	~Student();

	int returnGrade();
	void printInfo();

private:
	string name, num;
	int grade;
};

int main(int argc, char *argv[])
{
	int n, max=0, min=0;
	cin >> n;
	Student *s = new Student[n];
	for (int i = 1; i < n; i++) {
		max = s[max].returnGrade() > s[i].returnGrade() ? max : i;
		min = s[min].returnGrade() < s[i].returnGrade() ? min : i;
	}
	s[max].printInfo();
	s[min].printInfo();
	return 0;
}

Student::Student()
{
	cin >> this->name >> this->num >> this->grade;
}

Student::~Student()
{
}

int Student::returnGrade()
{
	return this->grade;
}

void Student::printInfo()
{
	cout << this->name << " " << this->num << endl;
}
