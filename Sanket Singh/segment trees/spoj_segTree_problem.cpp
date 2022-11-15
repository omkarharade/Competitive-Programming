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
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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



template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &in, pair<T1, T2> &p) { return (in >> p.first >> p.second);}
template<typename T> // cin >> vector<T>
istream& operator>>(istream &in, vector<T> &v) {for (auto &it : v) cin >> it; return in;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &out, const pair<T1, T2> &p) {return (out << p.first << " " << p.second); }
template<typename T> //cout << vector<T>
ostream& operator<<(ostream &out, const vector<T> &c) {for (auto &it : c) cout << it << " "; return out;}


void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
}

void update(vi &arr, vi &segTree, int s, int e, int tIdx, int indx, int type) {

	if (s == e) {
		if (type == 1) arr[indx]++;
		else arr[indx]--;

		segTree[tIdx] = arr[indx];
		return;
	}

	int mid = s + (e - s) / 2;

	if (indx > mid) {

		update(arr, segTree, mid + 1, e, 2 * tIdx + 1, indx, type);

	}
	else {

		update(arr, segTree, s, mid, 2 * tIdx, indx, type);

	}

	segTree[tIdx] = segTree[2 * tIdx] + segTree[2 * tIdx + 1];

}


int query(vi &segTree, int s, int e, int tIdx, int l, int r) {

	if (s > r or e < l) return 0;

	if (s >= l and e <= r) return segTree[tIdx];

	int mid = s + (e - s) / 2;

	int left = query(segTree, s, mid, 2 * tIdx, l, r);
	int right = query(segTree, mid + 1, e, 2 * tIdx + 1, l, r);

	return left + right;
}


void solve() {
	// solve here....

	int n;
	cin >> n;

	vi arr(n, 0);
	vi segTree(4 * n, 0);


	int q;
	cin >> q;

	while (q--) {

		int type;
		cin >> type;

		if (type == 1) {

			int indx;
			cin >> indx;
			update(arr, segTree, 0, n - 1, 1, indx, 1);
		}
		else if (type == 2) {

			int indx;
			cin >> indx;
			update(arr, segTree, 0, n - 1, 1, indx, 2);
		}
		else {

			int l, r;
			cin >> l >> r;
			cout << "set bit count : " << query(segTree, 0, n - 1, 1, l, r) << nline;
		}
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