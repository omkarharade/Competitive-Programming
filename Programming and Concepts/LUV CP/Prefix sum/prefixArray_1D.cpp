#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
const int N = 1e5 + 10;

int a[N];
int pf[N];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pf[i] = pf[i - 1] + a[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;

		cout <<
	}


	return 0;
}