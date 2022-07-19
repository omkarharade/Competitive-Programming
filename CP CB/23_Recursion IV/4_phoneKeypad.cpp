#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

char keypad [][8] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "wxyz"};

void printPass(string &input, int i, int n, string output) {

	if (i == n) {
		cout << output <<  nline;
		return;
	}

	int digit = (input[i] - '0');

	if ((digit == 1) or (digit == 0)) printPass(input, i + 1, n, output);

	for (int j = 0; keypad[digit][j] != '\0' ; ++j)
	{
		// cout << (keypad[digit][j]) << nline;
		printPass(input, i + 1, n, output + keypad[digit][j]);
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	string input;
	cin >> input;
	cout << input << nline;

	int n = input.length();

	printPass(input, 0, n, "");


	return 0;
}