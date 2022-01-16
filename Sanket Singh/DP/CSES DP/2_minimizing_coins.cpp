
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

vector<int> coins;
vector<int> dp;

int minimizingCoins(int x, int n) {

	if (x == 0) return 0;

	int minCoins = 1e9;

	for (int i = 0; i < n; ++i)
	{
		if (x - coins[i] >= 0) {
			minCoins = min(minCoins, 1 + minimizingCoins(x - coins[i] , n));
		}
	}

	return (minCoins == 1e9 ? 1e9 : minCoins);
}

int minimizingCoinsDP(int x, int n) {

	if (x == 0) return 0;
	if (dp[x] != -1) return dp[x];

	int minCoins = 1e9;
	for (int i = 0; i < n; ++i)
	{
		if (x - coins[i] >= 0) {
			minCoins = min(minCoins, 1 + minimizingCoins(x - coins[i], n));
		}
	}

	return dp[x] = (minCoins == 1e9 ? 1e9 : minCoins);
}

int minimizingCoinsBU(int x, int n) {

	vector<int>DP(x + 1, 0);
	DP[0] = 0;

	for (int i = 1; i <= x; ++i)
	{
		int minCoins = 1e9;

		for (int j = 0; j < n; ++j)
		{
			if (i - coins[j] >= 0) {
				minCoins = min(minCoins, 1 + DP[i - coins[j]]);
			}
		}
		DP[i] = (minCoins == 1e9 ? 1e9 : minCoins);
	}
	debug(DP)
	return DP[x];
}

void solve() {
	// solve here....

	int n, x;
	cin >> n >> x;

	coins.resize(n);
	dp.resize(x + 1, -1);

	for (int i = 0; i < n; ++i)
	{
		cin >> coins[i];
	}

	// int ans = minimizingCoins(x, n);
	// int ansDP = minimizingCoinsDP(x, n);
	int ansBU = minimizingCoinsBU(x, n);

	// cout << (ans == 1e9 ? -1 : ans) << nline;
	// cout << (ansDP == 1e9 ? -1 : ansDP) << nline;
	cout << (ansBU == 1e9 ? -1 : ansBU) << nline;

}



int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t = 1;
	// cin >> t;

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