#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
const int M = 1e9 + 7;
const int N = 1e6 + 10;

int binExpoIter(int a, int  b, int m) {
	int ans = 1;

	while (b > 0) {

		if (b & 1) {

			// ...(when M is smaller than 1e9)

			ans  = (ans * 1LL * a) % m;

			// when M is smaller than 1e18

			// ans = binMultiply(ans, a);
		}
		a = (a * 1LL * a) % m;
		b >>= 1;
	}

	return ans;
}

// There are N childrens and K toffees. K < N
// Count the number of ways to distribute toffee
// among N students such that each students get 1 toffee only
//  --> nCk , % M and  M = 10^9+ 7
//  N < 10^6, k < N < 10^6
//  n! / ((n-r)! *r!)


int fact[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here
	// N = 1e6 + 10

	fact[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		fact[i] = (fact[i - 1] * 1LL *  i) % M;
	}

	int q; cin >> q;

	while (q--) {

		int n, k; cin >> n >> k;

		int ans = fact[n];
		int denom = (fact[n - k] * 1LL * fact[k]);
		cout << ans << nline;
		cout << denom << nline;

		ans = (ans * 1LL * binExpoIter(denom, M - 2, M)) % M;

		cout << ans << nline;
	}

	return 0;
}