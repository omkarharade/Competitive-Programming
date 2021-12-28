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


#ifndef OMega13
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
#define fastIO ios::sync_with_stdio(0);cin.tie(0);

bool usaco = false;

void IO(string s) {
	fastIO
	if (s.empty()) {
#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
#endif
	}
	else {
		usaco = true;
		freopen((s + ".in").c_str(), "r", stdin);
		freopen((s + ".out").c_str(), "w", stdout);
	}
}


void solve() {
	// solve here....

	int n;
	cin >> n;

	vector<int>cow(n + 1), id(n + 1), ans(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> cow[i];
	}

	debug(cow)

	for (int i = 1; i <= n; ++i)
	{
		cin >> id[i];
	}
	debug(id)

	for (int i = 1; i <= n; ++i)
	{
		ans[cow[i]] = id[i];
	}


	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << nline;
	}

}
int main()
{
	clock_t begin = clock();
	fastIO
	IO("shuffle");
	// Write your code here....

	int t = 1;

	while (t-- > 0)
	{
		solve();
	}


	if (!usaco) {
#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	}
	return 0;
}