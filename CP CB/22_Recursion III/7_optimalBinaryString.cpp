#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int noConsecutiveOnes(string &s, int n) {

	if (n == 1) return 2;
	if (n == 2) return 3;

	return noConsecutiveOnes(s, n - 1) + noConsecutiveOnes(s, n - 2);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	string s;
	cin >> s;


	cout << noConsecutiveOnes(s, n) << nline;


	return 0;
}