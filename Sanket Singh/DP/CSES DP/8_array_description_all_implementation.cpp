
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
}

vector<int> arr;


int noOfArraysBU(int m, int n) {

	vector<vector<int>> DP(m + 1, vector<int>(n, 0));



	for (int i = 0; i < n; ++i)
	{

		// :::::::::::::base case :::::::::::::::::::::::::::::::

		if (i == 0) {

			if (arr[i] != 0) {
				DP[arr[i]][i] = 1;
			}
			else {
				for (int e = 1; e <= m; ++e)
				{
					DP[e][i] = 1;
				}
			}
			continue;
		}

		// :::::::::::::::::::: base case end ::::::::::::::::::::::::::::::::::::

		if (arr[i] != 0) {

			DP[arr[i]][i] = (DP[arr[i] - 1][i - 1] % MOD) + (DP[arr[i]][i - 1] % MOD) +  ( arr[i] + 1 <= m ? (DP[arr[i] + 1][i - 1] % MOD) : 0);
			DP[arr[i]][i] %= MOD;
		}
		else {
			for (int e = 1; e <= m; ++e)
			{
				DP[e][i] += (DP[e - 1][i - 1] % MOD);
				DP[e][i] += (DP[e][i - 1] % MOD);
				DP[e][i] += (e + 1 <= m ? (DP[e + 1][i - 1] % MOD) : 0);
				DP[e][i] %= MOD;
			}
		}
	}

	if (arr[n - 1] != 0) {
		return DP[arr[n - 1]][n - 1];
	}
	else {

		ll ans = 0;
		for (int e = 1; e <= m; ++e)
		{
			ans = (ans + DP[e][n - 1]) % MOD;
		}
		return ans;
	}
}

void solve() {
	// solve here....

	int n, m;
	cin >> n >> m;

	arr.resize(n);
	dp.resize(m + 1);

	for (int i = 0; i <= m; ++i)
	{
		dp[i].resize(n, -1);
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << noOfArrays(m, n - 1, m, n) << nline;
	cout << noOfArraysDP(m, n - 1, m, n) << nline;
	cout << noOfArraysBU(m, n) << nline;

}

int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t = 1;

	while (t-- > 0)
	{
		solve();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}