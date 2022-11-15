#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
}

class Node {

public:

	ll sum;
	ll maxSum;
	ll bps;
	ll bss;
};

void build(vi &arr, vector<Node> &segTree, ll s, ll e, ll tIdx) {

	if (s == e) {
		segTree[tIdx].sum = arr[s];
		segTree[tIdx].maxSum = arr[s];
		segTree[tIdx].bps = arr[s];
		segTree[tIdx].bss = arr[s];
		return;
	}
	ll mid = s + (e - s) / 2;

	build(arr, segTree, s, mid, 2 * tIdx);
	build(arr, segTree, mid + 1, e, 2 * tIdx + 1);

	ll left = 2 * tIdx, right = 2 * tIdx + 1;
	segTree[tIdx].sum = (segTree[left].sum + segTree[right].sum);
	segTree[tIdx].bps = max(segTree[left].bps, segTree[left].sum + segTree[right].bps);
	segTree[tIdx].bss = max(segTree[right].bss, segTree[right].sum + segTree[left].bss);

	segTree[tIdx].maxSum =
	max({
		segTree[left].maxSum,
		segTree[right].maxSum,
		segTree[left].sum + segTree[right].bps,
		segTree[right].sum + segTree[left].bss,
		segTree[left].bss + segTree[right].bps
	});
}

Node query(vector<Node> &segTree, ll s, ll e, ll tIdx, ll l, ll r) {

	Node result;
	result. sum = result. maxSum = result. bps = result. bss = INT_MIN;

	if (r < s or l > e) return result;
	if (s >= l and e <= r) return segTree[tIdx];

	ll mid = s + (e - s) / 2;

	Node left = query(segTree, s, mid, 2 * tIdx, l, r);
	Node right = query(segTree, mid + 1, e, 2 * tIdx + 1, l, r);

	result. sum = left. sum + right. sum;
	result. bps = max(left. bps, left. sum + right. bps);
	result. bss = max(right. bss, right. sum + left. bss);

	result.maxSum = max({
		left. maxSum,
		right.maxSum,
		left. sum + right.bps,
		right.sum + left. bss,
		left. bss + right.bps
	});


	return result;
}

void solve() {
	// solve here....

	int n;
	cin >> n;

	vi arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	vector<Node> segTree(4 * n);
	build(arr, segTree, 0, n - 1, 1);

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		Node res = query(segTree, 0, n - 1, 1, l, r);
		cout << res.maxSum << nline;

	}

}

int main()
{
	file_i_o();
	// Write your code here....
	solve();

	return 0;
}