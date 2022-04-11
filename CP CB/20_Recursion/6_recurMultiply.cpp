#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


int recurMultiply(int a, int b) {

	if (b == 0) return 0;
	return a + recurMultiply(a, b - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	cout << recurMultiply(8, 9) << nline;


	return 0;
}