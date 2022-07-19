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

/*

input 

2

3
0 1 -1
1 2 -2
2 0 3

3
0 1 -1
1 2 -2
2 0 -3


*/

int N = 2510;
vector<ll> dist(N, 1e18);

void init(int n){

	for (int i = 0; i < n; ++i)
	{
		dist[i] = 1e18;
	}
}

void solve(){
	// solve here....

	int n;
	cin >> n;

	init(n);

	vector<vector<ll>> edges(n, vector<ll>(3));

	for (int i = 0; i < n; ++i)
	{
		cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
	}

	// let the source be 0
	dist[0] = 0;

	// n-1 relaxations
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < edges.size(); ++j)
		{
			ll src = edges[j][0];
			ll dest = edges[j][1];
			ll wt = edges[j][2];

			if(dist[src] != 1e18 and dist[src] + wt < dist[dest]){
				dist[dest] = dist[src] + wt;
			}
		}
	}

	bool negCyclePresent = 0;

	for (int j = 0; j < edges.size(); ++j)
	{
		ll src = edges[j][0];
		ll dest = edges[j][1];
		ll wt = edges[j][2];

		if(dist[src] != 1e18 and dist[src] + wt < dist[dest]){
			negCyclePresent = 1;
			break;
		}
	}

	if(negCyclePresent){
		cout << -1 << nline;
	}
	else{
		for (int i = 0; i < n; ++i)
		{
			cout << dist[i] << " ";
		}
		cout << nline;
	}

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