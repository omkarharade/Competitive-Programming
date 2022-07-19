#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int stringToInt(string &s, int n) {

	if (n == 0) {
		return 0;
	}
	return (stringToInt(s, n - 1) * 10) + (int(s[n - 1] - '1') + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n; cin >> n;
	string s;
	cin >> s;

	cout << stringToInt(s, n) << nline;


	return 0;
}