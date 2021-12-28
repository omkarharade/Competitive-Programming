#include <bits/stdc++.h>
using namespace std;
#define nline "\n"



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n; cin >> n;
	int cnt = 0, sum = 0;

	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0) {
			cnt++;
			sum += i;
			cout << i << " " << n / i << nline;

			if (n / i != i) {
				sum += (n / i);
				cnt += 1;
			}
		}

	}

	cout << "count = " << cnt << " sum = " << sum << nline;


	return 0;
}