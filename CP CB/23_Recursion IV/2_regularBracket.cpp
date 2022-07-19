#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

void brackets(int n, int openCnt, int closeCnt, string ans) {

	if ((openCnt == n) and (closeCnt == n)) {
		cout << ans << nline;
		return;
	}


	if (openCnt < n) {
		brackets(n, openCnt + 1, closeCnt, ans + '(');
	}

	if (openCnt > closeCnt) {
		brackets(n, openCnt, closeCnt + 1, ans + ')');
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	brackets(n, 0, 0, "");


	return 0;
}