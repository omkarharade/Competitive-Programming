#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


class Student {

public:

	int id;
	float salary;
	string name;

	void display() {
		cout << id << " " << name << nline;
	}

};

int main() {

	Student s1;

	s1.id = 201;
	s1.salary = 10000.0000;
	s1.name = "Omkar Harade";

	cout << "ID : " << s1.id << nline;
	cout << "Salary : " << s1.salary << nline;
	cout << "Name : " << s1.name << nline;


	return 0;
}