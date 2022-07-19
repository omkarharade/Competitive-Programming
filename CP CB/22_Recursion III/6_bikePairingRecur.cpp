#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


int bikePairing(int n) {

	if (n == 1) return 1;
	if (n == 0) return 1;

	return bikePairing(n - 1) + (n - 1) * bikePairing(n - 2);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	cout << bikePairing(n) << nline;


	return 0;
}