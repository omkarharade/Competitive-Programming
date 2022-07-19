#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int fastPower(int a, int n) {

	if (n == 0) return 1;

	if (n & 1) {
		// odd

		int halfAns = fastPower(a, (n - 1) / 2);
		return a * halfAns * halfAns;
	}
	else {
		// even

		int halfAns = fastPower(a, n / 2);
		return halfAns * halfAns;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	cout << fastPower(3, 4) << nline;


	return 0;
}