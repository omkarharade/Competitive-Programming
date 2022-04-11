#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int recurPower(int a, int n) {

	if (n == 0) return 1;
	return a * recurPower(a, n - 1);
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	cout << recurPower(9, 2) << nline;


	return 0;
}