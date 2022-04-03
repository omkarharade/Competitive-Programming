#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


/*  Problem - Unique Number 2N + 1
	given a list of numbers where every number
	occurs twice except one number, find that
	number

	Input:
	7
	3 1 2 1 2 3 7

	Expected Output:
	7
*/


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	long long ans = 0;

	for (int i = 0; i < n; ++i)
	{
		long long in;
		cin >> in;

		ans ^= in;
	}

	cout << ans << nline;


	return 0;
}