#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*
	time complexity : O(N)
	space complexity : O(1)

*/


int minOpsToPalindrome(vector<int>& vec, int n) {

	int lo = -1, hi = n;
	int left = 0, right = 0;
	int opsCount = 0;


	while (lo < hi) {

		if (left < right) {
			lo++;
			left += vec[lo];
			opsCount++;
		}
		else if (right < left) {
			hi--;
			right += vec[hi];
			opsCount++;
		}
		else {

			lo++;
			hi--;
			left = vec[lo];
			right = vec[hi];
		}
	}

	return opsCount;
}


int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	cout << minOpsToPalindrome(vec, n) << nline;

	return 0;
}