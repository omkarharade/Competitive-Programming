#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int knapsack(int wt[], int val[], int W, int n) {

	if (W == 0 or n == 0) {
		return 0;
	}

	if (wt[n - 1] <= W) {

		return max(wt[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
	}
	else return knapsack(wt, val, W, n - 1);
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n = 4, W = 8;

	int wt[] = {3, 4, 6, 5};
	int val[] = {2, 3, 1, 4};

	int profit = knapsack(wt, val, W, n);
	cout << profit << nline;


	return 0;
}