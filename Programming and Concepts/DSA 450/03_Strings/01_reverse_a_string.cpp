#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void reverse_string(string &s) {

	int n = s.length();

	int lo = 0, hi = n - 1;

	while (lo < hi) {

		swap(s[lo], s[hi]);
		lo++, hi--;
	}

	// Time Complexity : O(N)
}

int main() {
	string s;
	getline(cin, s);

	reverse_string(s);

	cout << s << nline;

	return 0;
}