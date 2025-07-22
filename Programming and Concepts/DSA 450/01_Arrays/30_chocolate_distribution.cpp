#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

Naive solution : recursive solution

	sort the array first and then check recursively that is it possible to
	give m students 1 chocolate each from present number of chocolates

	use divide and conquer for that
	taking minimum of rec(arr, l, r-1) and rec(arr, l+1, r)


*/

int rec(vector<int>& vec, int l, int r, int m) {

	if (l >= r) return INT_MAX;
	if (r - l + 1 < m) return INT_MAX;

	int ans = INT_MAX;

	ans = min(rec(vec, l + 1, r, m), rec(vec, l, r - 1, m));
	ans = min(ans, vec[r] - vec[l]);

	return ans;
}

/*

Optimal Solution: sliding window kind of solution with a frame of length m on sorted array

*/

int findMinDiff_optimal(vector<int> a, int n, int m) {

	sort(a.begin(), a.end());
	int minDiff = INT_MAX;

	for (int i = 0; i + m - 1 < n; i++) {

		minDiff = min(minDiff, a[i + m - 1] - a[i]);
	}

	return minDiff;

}

int main() {


	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	int ans = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	// ans = rec(vec, 0, n - 1, m);

	ans = findMinDiff_optimal(vec, n, m);
	cout << ans << nline;


	return 0;
}