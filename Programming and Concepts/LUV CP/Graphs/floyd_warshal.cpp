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

//////////////////////////////////////////////////////////////////////////////////////

/* 

There are n cities and m roads between them.
Your task is to process q queries where you have to determine the length of the shortest
 route between two given cities.

Input

The first input line has three integers n, m and q:
the number of cities, roads, and queries.

Then, there are m lines describing the roads. Each line has three integers
a, b and c: there is a road between cities a and b whose length is c. 
All roads are two-way roads.

Finally, there are q lines describing the queries. 
Each line has two integers a and b: determine the length of the shortest route between cities a and b.

Output

Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1≤n≤500
1≤m≤n2
1≤q≤105
1≤a,b≤n
1≤c≤109
Example

Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3


*/
const int N = 510;
ll dist[N][N];

void solve(){
	// solve here....

	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < 510; ++i)
	{
		for (int j = 0; j < 510; ++j)
		{
			if(i == j){
				dist[i][j] = 0;
			}
			else dist[i][j] = 1e18;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;
		dist[v1][v2] = min(dist[v1][v2], 1LL*wt);	
		dist[v2][v1] = min(dist[v1][v2], 1LL*wt);	
	}

	for (int k = 1; k <= n ; ++k)
	{
		for (int i = 1; i <= n ; ++i)
		{
			for (int j = 1; j <= n ; ++j)
			{
				if(dist[i][k] != 1e18 and dist[k][j] != 1e18)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}


	while(q--){

		int v1, v2;
		cin >> v1 >> v2;

		if(dist[v1][v2] == 1e18) cout << -1 << nline;
		else cout << dist[v1][v2] << nline;
	}
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