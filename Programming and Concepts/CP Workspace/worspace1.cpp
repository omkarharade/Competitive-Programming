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

// variables declarations

const int N = 1e3+10;
vector<vector<char>> vec(N, vector<char>(N, '.'));
vector<vector<bool>> vis(N, vector<bool>(N, false));
vector<vector<int>> dp(N, vector<int>(N, -1));

bool usaco = false;

void IO(string s) {
	fastIO
	if (s.empty()) {
#ifndef ONLINE_JUDGE
		freopen("error.txt", "w", stderr);
#endif
	}
	else {
		usaco = true;
		freopen((s + ".in").c_str(), "r", stdin);
		freopen((s + ".out").c_str(), "w", stdout);
	}
}

void f(string &s, int n, int i) {

// boundary checks 

bool isSafe(int x, int y, int n){

	return x >= 0 and y >= 0 and x < n and  y < n;
}

// initializations 

void init(int n){

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			vis[i][j] = 0;
			dp[i][j] = -1;
		}
	}
}

// movements array

vector<pair<int, int>> movements = {
	{-1, 2}, {-2, 1}, {1, 2}, {2, 1}
};

// recursive fxn to get ans

void getMaxEnemy(int x, int y, int n){

	// base case
	if(!isSafe(x, y, n)) return;
	if(dp[x][y] != -1) return;
	if (vis[x][y]) return;
	//..........................................................


	vis[x][y] = 1;

	bool enemyPresent = 0;
	int maxEnemy = 0;
	if(vec[x][y] == 'P') enemyPresent = 1;


	for (int i = 0; i < movements.size(); ++i)
	{
		int newX = x + movements[i].ff;
		int newY = y + movements[i].ss;

		if(!isSafe(newX, newY, n)) continue;

		getMaxEnemy(newX, newY, n);
		maxEnemy = max(maxEnemy, dp[newX][newY]);
	}

	dp[x][y] = maxEnemy + enemyPresent;
	vis[x][y] = 0;
}

void solve(){
	// solve here....

	int n;
	cin >> n;

	init(n); // to be implemented
	int xK = -1, yK = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> vec[i][j];

			if(vec[i][j] == 'K'){
				xK = i;
				yK = j;
			}
		}
	}

	getMaxEnemy(xK, yK, n);

	cout << dp[xK][yK] << nline;
}

int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t = 1;
	cin >> t;

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