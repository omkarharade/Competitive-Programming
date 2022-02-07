#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


// [.........top down (recursive).........]
int fibRecur(int n) {

	if (n == 0 or n == 1) return n;

	return fibRecur(n - 1) + fibRecur(n - 2);
}





// {..Dynamic programming..}

//[......... top down (recursive) memoisation........]

int dp[int(1e5)];

int fibDP(int n) {

	if (n == 0 or n == 1) return n;

	if (dp[n] != -1) return dp[n];

	return dp[n] = fibDP(n - 1) + fibDP(n - 2);
}

// [.........bottom up (iterative).........]

int fibIter(int n) {

	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	memset(dp, -1, sizeof(dp));

	cout << fibRecur(40) << nline;
	cout << fibDP(40) << nline;
	cout << fibIter(40) << nline;


	return 0;
}
