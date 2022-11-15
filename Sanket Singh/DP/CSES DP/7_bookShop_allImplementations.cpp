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
#define debug(x)       \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
	cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
	cerr << "{";
	_print(p.ff);
	cerr << ",";
	_print(p.ss);
	cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(unordered_set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
}

vector<ll> pages;
vector<ll> price;

ll maxPages(ll budget, ll indx, ll n)
{

	if (indx == n)
		return 0;
	if (budget < price[indx])
	{
		return maxPages(budget, indx + 1, n);
	}

	return max(maxPages(budget, indx + 1, n), pages[indx] + maxPages(budget - price[indx], indx + 1, n));
}

vector<vector<ll>> dp;

ll maxPagesDP(ll budget, ll indx, ll n)
{
	if (indx == n)
		return 0;

	if (dp[indx][budget] != -1)
	{
		return dp[indx][budget];
	}

	if (budget < price[indx])
	{
		return maxPages(budget, indx + 1, n);
	}

	return dp[indx][budget] = max(maxPages(budget, indx + 1, n), pages[indx] + maxPages(budget - price[indx], indx + 1, n));
}

ll maxPagesBU(ll budget, ll n)
{

	vector<vector<ll>> DP(n + 1, vector<ll>(budget + 1));

	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j <= budget; ++j)
		{

			if (i == 0)
			{
				DP[i][j] = (j < price[i] ? 0 : pages[i]);
			}
			else
			{

				if (j < price[i])
				{
					DP[i][j] = DP[i - 1][j];
				}

				else
				{
					DP[i][j] = max(DP[i - 1][j], pages[i] + DP[i - 1][j - price[i]]);
				}
			}
		}
	}

	return DP[n - 1][budget];
}

void solve()
{
	// solve here....

	ll n, budget;
	cin >> n >> budget;

	pages.resize(n);
	price.resize(n);
	dp.resize(n + 1);

	for (ll i = 0; i <= n; ++i)
	{
		dp[i].resize(budget + 1, -1);
	}

	for (ll i = 0; i < n; ++i)
	{
		cin >> price[i];
	}

	for (ll i = 0; i < n; ++i)
	{
		cin >> pages[i];
	}

	// cout << maxPages(budget, 0, n) << nline;
	// cout << maxPagesDP(budget, 0, n) << nline;
	cout << maxPagesBU(budget, n) << nline;
}

int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll t = 1;
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
