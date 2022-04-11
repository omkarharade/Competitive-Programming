#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

char arr [] = {'0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


void generateStrings(string input, int i, int n, string output) {

	if (i == n) {
		cout << output << nline;
		return;
	}

	if (input[i] == '0') {
		generateStrings(input, i + 1, n, output);
	}


	// recursive one character

	int digit1 = input[i] - '0';
	generateStrings(input, i + 1, n, output + arr[digit1]);


	// recursive two character

	if (i + 1 < n) {

		int digit2 = input[i + 1] - '0';

		digit2 = ((10 * digit1) + digit2 );

		if (digit2 <= 26 ) {

			generateStrings(input, i + 2, n, output + arr[digit2]);
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	string s;
	cin >> s;

	generateStrings(s, 0, s.length(), "" );


	return 0;
}
