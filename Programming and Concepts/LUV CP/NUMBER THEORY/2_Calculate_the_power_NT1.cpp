#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int binExpoIter(long long a, long long b, long long m) {
	int ans = 1;

	while (b > 0) {

		if (b & 1) {

			ans  = (ans * 1LL * a) % m;
		}

		a = (a * 1LL * a) % m;
		b >>= 1;
	}

	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here

	long long a, b, m;
	m = 1e9 + 7;
	cin >> a >> b;

	int ans = binExpoIter(a, b, m);
	cout << ans << nline;
	return 0;
}