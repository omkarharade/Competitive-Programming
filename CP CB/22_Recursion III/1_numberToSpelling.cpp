#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

vector<string> spelling(10);

void numberToSpelling(int num) {

	if (num == 0) {
		return;
	}

	numberToSpelling(num / 10);

	cout << spelling[num % 10] << " ";

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	spelling[0] = "zero";
	spelling[1] = "one";
	spelling[2] = "two";
	spelling[3] = "three";
	spelling[4] = "four";
	spelling[5] = "five";
	spelling[6] = "six";
	spelling[7] = "seven";
	spelling[8] = "eight";
	spelling[9] = "nine";

	int n;
	cin >> n;

	numberToSpelling(n);


	return 0;
}