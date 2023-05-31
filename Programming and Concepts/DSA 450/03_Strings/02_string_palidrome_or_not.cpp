#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int isPalindrome(string S)
{
	// Your code goes here

	int lo = 0, hi = S.length() - 1;
	bool ok = 1;

	while (lo < hi) {

		if (S[lo++] != S[hi--]) {
			ok = 0;
			break;
		}
	}

	return ok;
}

int main() {

	string s;
	cin >> s;

	cout << (isPalindrome(s) ? "YES" : "NO") << nline;

	return 0;
}