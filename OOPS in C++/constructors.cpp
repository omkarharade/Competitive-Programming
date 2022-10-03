#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


class Student {

public:

	int id;
	float salary;
	string name;

	Student(int cId, string cName, float cSalary) {

		this -> id = cId;
		this -> name = cName;
		this -> salary = cSalary;

	}

	~Student() {

		cout << "Destructor Invoked " << nline;
	}

	void display() {
		cout << "ID: " << id << nline;
		cout << "Name: " << name << nline;
		cout << "Salary: " << salary << nline;
		cout << nline;
	}

};

int main() {

	Student s1(101, "Omkar Harade", 10000.0000);
	Student s2(101, "Sahil Nazare", 20000.0000);
	s1.display();
	s2.display();


	return 0;
}