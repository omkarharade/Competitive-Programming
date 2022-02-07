#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
vector<int> dp;

int minStepsToOne(int n) {

	if (n == 1) return 0;

	int minSteps = INT_MAX;

	minSteps = min(minSteps, 1 + minStepsToOne(n - 1));

	if (n % 2 == 0 and n % 3 == 0) {
		minSteps = min(1 + minStepsToOne(n / 2), minSteps);
		minSteps = min(minSteps, 1 + minStepsToOne(n / 3));
	}
	else if (n % 2 == 0) {
		minSteps = min(1 + minStepsToOne(n / 2), minSteps);
	}
	else if (n % 3 == 0) {
		minSteps = min(1 + minStepsToOne(n / 3), minSteps);
	}


	return minSteps;
}



int minStepsToOneDP(int n) {

	if (n == 1) return 0;
	if (n == 2 or n == 3) return 1;

	int div_by_2 = 1e5;
	int div_by_3 = 1e5;
	int sub_by_1 = 1e5;

	if (dp[n] != -1) return dp[n];

	sub_by_1 = 1 + minStepsToOneDP(n - 1);


	if (n % 2 == 0) {
		div_by_2 = 1 + minStepsToOneDP(n / 2);
	}

	if (n % 3 == 0) {
		div_by_3 = 1 + minStepsToOneDP(n / 3);
	}

	return dp[n] = min(div_by_2, min(div_by_3, sub_by_1));
}

int minStepsToOneBU(int n) {
	vector<int> DP(n + 1, -1);

	DP[1] = 0, DP[2] = DP[3] = 1;

	for (int i = 4; i <= n; ++i)
	{
		int div_by_2 = 1e9;
		int div_by_3 = 1e9;
		int sub_by_1 = 1e9;

		sub_by_1 = 1 +  DP[i - 1];
		if (i % 2 == 0) {
			div_by_2 = 1 + DP[i / 2];
		}

		if (i % 3 == 0) {
			div_by_3 = 1 + DP[i / 3];
		}

		DP[i] = min(div_by_2, min(div_by_3, sub_by_1));
	}

	return DP[n];

}

// -1 -1 -1 -1 -1 3 -1 -1 -1 2 3

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n = 14;

	dp.resize(n + 1, -1);

	cout <<  minStepsToOneDP(n) << nline;

	for (int i = 0; i <= n; ++i)
	{
		cout << dp[i] << " ";
	}
	cout << nline;
	cout <<  minStepsToOneBU(n) << nline;
	return 0;
}
