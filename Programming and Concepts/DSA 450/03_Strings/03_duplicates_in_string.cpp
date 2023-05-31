#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

Method 1: use hasing using array

Method 2 : use hasing using Map (code available below)

*/

void print_duplicates(string &s) {

	map<char, int> charCount;
	int count = 0;

	for (int i = 0; i < s.length(); ++i)
	{
		charCount[s[i]]++;
	}

	for (auto m : charCount) {

		if (m.second > 1) {
			cout << m.first << " : " << m.second << nline;
		}
	}
}

int main() {

	string s;
	cin >> s;

	print_duplicates(s);

	return 0;
}