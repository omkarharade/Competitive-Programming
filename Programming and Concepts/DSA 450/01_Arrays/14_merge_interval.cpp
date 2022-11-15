#include <bits/stdc++.h>
using namespace std;


static bool cmp(vector<int> &a, vector<int> &b) {

	if (a[0] ==  b[0]) {
		return a[1] < b[1];
	}
	else return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), cmp);
	int n = intervals.size();
	vector<vector<int>> ans;
	vector<int> currAns(2, -1);

	int lo = intervals[0][0];
	int hi = intervals[0][1];
	currAns[0] = lo;
	currAns[1] = hi;

	for (int i = 1; i < n; i++) {
		int currLo = intervals[i][0];
		int currHi = intervals[i][1];

		if (lo <= currLo and hi >= currLo) {

			hi = max(hi, currHi);
		}
		else {
			currAns[0] = lo;
			currAns[1] = hi;
			ans.push_back(currAns);
			lo = currAns[0] = currLo;
			hi = currAns[1] = currHi;
		}
	}
	currAns[0] = lo;
	currAns[1] = hi;

	ans.push_back(currAns);

	return ans;
}

void solve() {
	// solve here....

	int n;
	cin >> n;

	vector<vector<int>> g(n, vector<int>(2));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> g[i][j];
		}
	}

	vector<vector<int>> ans = merge(g);

	for (int i = 0; i < ans.size(); i++) {
		cout << "[ " << ans[i][0] << ", " << ans[i][1] << "}" << " , ";
	}
	cout << "\n";

}

int main()
{
	// Write your code here....

	int t = 1;

	while (t-- > 0)
	{
		solve();
	}

	return 0;
}