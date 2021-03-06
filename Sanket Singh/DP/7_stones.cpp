
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
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

vector<int> dp;


int winnerDP(vector<int> &stonesVec, vector<int> &dp, int n, int k) {

	if (k == 0) return 0;

	if (dp[k] != -1) return dp[k];

	int p1 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (k - stonesVec[i] >= 0) {
			if (winnerDP(stonesVec, dp, n, k - stonesVec[i]) == 0) {
				p1 = 1;
				break;
			}
		}
	}
	return dp[k] = p1;
}

int winnerBU(vector<int> &stonesVec, int n, int k) {

	vector<int> dp(k + 1, 0);

	// base case : dp[0] = 0;

	for (int i = 1; i <= k; ++i)
	{
		for (auto val : stonesVec) {

			if (val > i) continue;
			if (dp[i - val] == 0) {
				dp[i] = 1;
				break;
			}
		}
	}

	return dp[k];
}

void solve() {
	// solve here....

	int n, k;
	cin >> n >> k;

	dp.resize(k + 1, -1);

	vector<int> stonesVec(n);

	for (int i = 0; i < n; i++) cin >> stonesVec[i];

	int p1_DP = winnerDP(stonesVec, dp, n, k);
	cout << (p1_DP == 1 ? "First" : "Second") << nl;

	int p1_BU = winnerBU(stonesVec, n, k);

	cout << (p1_BU == 1 ? "First" : "Second") << nl;
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