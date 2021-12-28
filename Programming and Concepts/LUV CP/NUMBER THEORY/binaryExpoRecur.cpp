#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
const int M = 1e9 + 7;

int binMultiply(long long a, long long b) {
	int ans = 0;

	while (b > 0) {

		if (b & 1) {
			ans = (ans + a) % M;
		}
		a = (a + a) % M;
		b >>= 1;
	}
	return ans;
}


int binExpoRecur(int a, int b) {

	if (b == 0) return 1;

	int res = binExpoRecur(a, b / 2);
	if (b & 1) {
		return (1LL * a * res * res) % M;
	}
	else {
		return (1LL * res * res) % M ;
	}
}


int binExpoIter(int a, int b, int m) {
	int ans = 1;

	while (b > 0) {

		if (b & 1) {

			// ...(when M is aller than 1e9)

			ans  = (ans * 1LL * a) % m;

			// when M is smaller than 1e18

			// ans = binMultiply(ans, a);
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

	int a, b;
	cin >> a >> b;

	cout << binExpoRecur(a, b, M) << nline;
	cout << binExpoIter(a, b, M) << nline;

	return 0;
}