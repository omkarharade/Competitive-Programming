#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
vector<int> coins;
vector<int> dp;

int minCoins(int x, int n) {

	int coinsReq = INT_MAX;

	if (x == 0) return 0;

	for (int i = 0; i < n; ++i)
	{
		if (x - coins[i] >= 0)
			coinsReq = min( coinsReq,  1 + minCoins(x - coins[i], n));
	}

	return coinsReq;
}

int minCoinsDP(int x, int n) {

	int coinsReq = INT_MAX;

	if (x == 0) return 0;
	if (dp[x] != -1) return dp[x];

	for (int i = 0; i < n; ++i)
	{
		if (x - coins[i] >= 0)
			coinsReq = min( coinsReq,  1 + minCoinsDP(x - coins[i], n));
	}

	return dp[x] = coinsReq;
}

int minCoinsBU(int x, int n) {
	vector<int> DP(x + 1, 1e9);
	DP[0] = 0;

	for (int i = 1; i <= x; ++i)
	{
		int coinsReq = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if (i - coins[j] >= 0) {
				coinsReq = min(coinsReq, 1 + DP[i - coins[j]]);
			}
		}
		DP[i] = coinsReq;
	}

	return DP[x];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n, x;
	cin >> n >> x;

	coins.resize(n);
	dp.resize(x + 1, -1);

	for (int i = 0; i < n; ++i)
	{
		cin >> coins[i];
	}

	cout << minCoins(x, n) << nline;
	cout << minCoinsDP(x, n) << nline;
	cout << minCoinsBU(x, n) << nline;


	return 0;
}
