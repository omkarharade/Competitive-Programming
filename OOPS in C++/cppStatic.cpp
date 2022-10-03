#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

class Account {
public:
	int accno; //data member (also instance variable)
	string name; //data member(also instance variable)
	static float rateOfInterest;
	Account(int accno, string name)
	{
		this->accno = accno;
		this->name = name;
	}
	void display()
	{
		cout << accno << " " << name << " " << rateOfInterest << endl;

	}
};

class Account2 {

public:

	int accNo;
	string name;
	static int count;

	Account2(int accNo, string name) {

		this -> accNo;
		this -> name;
		count++;

	}

	void display() {

		cout << accNo << " " << name << nline;
	}
};

float Account::rateOfInterest = 6.5;
int Account2 :: count = 0;

int main() {

	Account acc1(101, "Omkar Harade");

	acc1.display();


	Account2 a1(201, "Sanjay");
	Account2 a2(202, "Nakul");
	Account2 a3(203, "Ranjana");


	a1.display();
	a2.display();
	a3.display();
	cout << "Total Objects are: " << Account2::count;


	return 0;
}