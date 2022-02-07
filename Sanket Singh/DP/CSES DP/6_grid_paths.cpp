
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

vector<vector<char>> grid;

bool isValid(int i, int j, int n) {

	if (((i < n) and (j < n) and (i >= 0) and (j >= 0)) and (grid[i][j] != '*')) return true;
	else return false;
}


int gridPaths(int i, int j, int n) {

	int paths = 0;
	if (grid[0][0] == '*') return 0;

	if (i == n - 1 and j == n - 1) return 1;
	if (isValid(i + 1, j, n)) {
		paths += gridPaths(i + 1, j, n);
		paths %= MOD;
	}
	if (isValid(i, j + 1, n)) {
		paths += gridPaths(i, j + 1, n);
		paths %= MOD;
	}

	return paths;
}

vector<vector<int>> dp;

int gridPathsDP(int i, int j, int n) {

	if (grid[0][0] == '*') return 0;

	if (isValid(i, j, n) and dp[i][j] != -1) {
		return dp[i][j];
	}

	if (i == n - 1 and j == n - 1) return 1;

	int paths = 0;

	if (isValid(i + 1, j, n)) {
		paths += gridPaths(i + 1, j, n);
		paths %= MOD;
	}

	if (isValid(i, j + 1, n)) {
		paths += gridPaths(i, j + 1, n);
		paths %= MOD;
	}

	return dp[i][j] = paths;
}

int gridPathsBU(int i, int j, int n) {

	if (grid[0][0] == '*') return 0;

	vector<vector<int>> DP(n, vector<int>(n, 0));
	DP[n - 1][n - 1] = 1;

	for (int i = n; i >= 0; --i)
	{
		for (int j = n; j >= 0; --j)
		{

			if (isValid(i + 1, j, n)) {
				DP[i][j] += DP[i + 1][j];
				DP[i][j] %= MOD;
			}

			if (isValid(i, j + 1, n)) {
				DP[i][j] += DP[i][j + 1];
				DP[i][j] %= MOD;
			}

		}
	}

	return DP[0][0];
}

void solve() {
	// solve here....

	int n;
	cin >> n;

	grid.resize(n);
	dp.resize(n);

	for (int i = 0; i < n; ++i)
	{
		grid[i].resize(n);
		dp[i].resize(n, -1);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];

		}
		debug(grid[i])
	}
	// cout << gridPaths(0, 0, n) << nline;
	// cout << gridPathsDP(0, 0, n) << nline;
	cout << gridPathsBU(0, 0, n) << nline;

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