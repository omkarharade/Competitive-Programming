
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

bool cmp(string a, string b) {

	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() > b.length();
}

void solve() {
	// solve here....

	string s0;

	string s1("hello");

	string s2 = "Hello World";
	string s3(s2);

	string s4 = s3;

	char a[] = {'a', 'b', 'c', '\0'};
	string s5(a);

	cout << s0 << nline;
	cout << s1 << nline;
	cout << s2 << nline;
	cout << s3 << nline;
	cout << s4 << nline;
	cout << s5 << nline;

	if (s0.empty()) {
		cout << "s0 is an empty string" << nline;
	}

	s0.append("I love C++");
	cout << s0 << nline;

	cout << s0.length() << nline;
	s0.clear();
	cout << s0.length() << nline;

	s0 = "apple";
	s1 = "mango";

	cout << s0.compare(s1) << nline; // if -1 then s0 is smaller, if 0 then same , if +ve then s0 is greater

	if (s1 > s0) {
		cout << "Mango is lexicographically greater than apple" << nline;
	}

	cout << s1[0] << nline;

	// find substring

	string s = "I want apple juice";

	int idx = s.find("apple");
	cout << idx << nline;

	string word = "apple";
	int len = word.length();
	s.erase(idx, len + 1 ); // +1 to remove xtra space
	cout << s << nline;


	int n;
	cin >> n;
	cin.get();

	string arrStr[100];

	for (int i = 0; i < n; ++i)
	{
		getline(cin, arrStr[i]);
	}

	sort(arrStr, arrStr + n, cmp);

	for (int i = 0; i < n; ++i)
	{
		cout << arrStr[i] << nline;
	}

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