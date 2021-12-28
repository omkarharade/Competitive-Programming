#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


void permutations(string &str, int l, int r) {

	if (l == r) {
		cout << str << nline;
		return;
	}

	for (int i = l; i <= r; ++i)
	{
		swap(str[l] , str[i]);

		permutations(str, l + 1, r);

		swap(str[l], str[i]);

	}


}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	string str; cin >> str;


	permutations(str, 0, str.length() - 1);

	return 0;
}