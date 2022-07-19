#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int profit(vector<int> &weights, vector<int> &prices, int capacity, int i, int n) {

	if ((i == n) or (capacity == 0)) return 0;
	int case1 = profit(weights, prices, capacity, i + 1, n);
	int case2 = 0;

	if (capacity - weights[i] >= 0) {

		case2 = prices[i] + profit(weights, prices, capacity - weights[i], i + 1, n);
	}

	return max(case1, case2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	vector<int> weights(n);
	vector<int> prices(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> prices[i];
	}

	int capacity;
	cin >> capacity;

	cout << profit(weights, prices, capacity, 0, n ) << nline;


	return 0;
}