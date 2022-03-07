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
#define fastIO ios::sync_with_stdio(0);cin.tie(0);



/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/

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

int n;
vector<vector<ll>> dp;
vector<vector<ll>>vec;

// day starting from 0
// activities 0 1 2

ll maxHappiness(int day, int prevSelection) {

	// base case
	if (day == n) return 0;

	ll maxHappy = -1;

	for (int i = 0; i < 3; ++i)
	{

		if (i != prevSelection)
			maxHappy = max(maxHappy, vec[day][i] + maxHappiness(day + 1, i));
	}

	return maxHappy;
}

ll maxHappinessDP(int day, int prevSelection) {

	// base case
	if (day == n) return 0;

	ll maxHappy = -1;

	for (int i = 0; i < 3; ++i)
	{
		if ((prevSelection != -1 ) and  (dp[day][prevSelection] != -1)) return dp[day][prevSelection];
		if (i != prevSelection)
			maxHappy = max(maxHappy, vec[day][i] + maxHappinessDP(day + 1, i));
	}

	if (prevSelection != -1) return dp[day][prevSelection] = maxHappy;
	else return maxHappy;
}



void solve() {
	// solve here....

	cin >> n;

	dp.resize(n);
	vec.resize(n);

	for (int i = 0; i < n; ++i)
	{
		dp[i].resize(3, -1);
		vec[i].resize(3);

	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> vec[i][j];
		}
	}

	debug(vec)

	cout << maxHappiness(0, -1) << nline;
	cout << maxHappinessDP(0, -1) << nline;

	debug(dp)
}
int main()
{
	clock_t begin = clock();
	fastIO
	IO("");
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