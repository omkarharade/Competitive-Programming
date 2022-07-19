#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

/*

                   " "
                   /   \
                  a     " "
                 / \      /  \
                ab  a    b   " "
              / \   /\   / \  / \
            abc ab ac a  bc b c " "

*/


void subset(string &s, int i, int n, string ans) {

	if (i == n) {
		cout << ans << nline;
		return;
	}

	subset(s, i + 1, n, ans + s[i]);
	subset(s, i + 1, n, ans);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	string s;
	cin >> s;

	subset(s, 0, s.length(), "");


	return 0;
}