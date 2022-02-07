#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; ++i)
	{
		if (isPrime[i]) {
			for (int j = 2 * i; j < N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	// time complexity = O(N * loglogN)

	int q; cin >> q;

	while (q--) {
		int num;
		cin >> num;

		if (isPrime[num]) {
			cout << "Prime" << nline;
		}
		else cout << "Not Prime" << nline;
	}
	return 0;
}