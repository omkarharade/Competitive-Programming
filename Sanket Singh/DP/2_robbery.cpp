#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int dp[(int)1e5];


int rob(vector<int> &vec, int i) {
	if (i == 0) {
		return vec[0];
	}
	else if (i == 1) {
		return max(vec[0], vec[1]);
	}

	return max(rob(vec, i - 1), vec[i] + rob(vec, i - 2));
}



int robDP(vector<int> &vec, int i) {

	if (i == 0) {
		return vec[0];
	}
	else if (i == 1) {
		return max(vec[0], vec[1]);
	}


	if (dp[i] != -1) return dp[i];

	return dp[i] = max(rob(vec, i - 1), vec[i] + rob(vec, i - 2));
}

int robIter(vector<int> &vec, int idx) {
	int dp[idx + 1];
	dp[0] = vec[0];
	dp[1] = max(vec[0], vec[1]);

	for (int i = 2; i <= idx; ++i)
	{
		dp[i] = max(dp[i - 1], vec[i] + dp[i - 2]);
	}

	return dp[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	memset(dp, -1, sizeof(dp));

	vector<int> vec;


	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(7);
	vec.push_back(9);


	int vecSize = vec.size();

	cout << rob(vec, vecSize - 1) << nline;
	cout << robDP(vec, vecSize - 1) << nline;
	cout << robIter(vec, vecSize - 1) << nline;





	return 0;
}
