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

// ignore above codes.....

const int N = 1e5 + 10;  // 1e5 = 1 * (10^5) 10 raised to 5
vector<int> graph[N];

// vector is basically dynamic array,
// and array of vector is the above defined graph;

int aliveSuccessor(vector<bool> &isAlive, int king) {

	queue<int> q; // queue initialize
	q.push(king); // push king

	while (!q.empty()) {

		// while loop runs till a successor is not found alive



		// take the value from front of the queue and pop it from queue
		int successor = q.front();
		q.pop();


		// if successor not alive , push its children

		if (!isAlive[successor]) {

			for (int child : graph[successor]) {

				q.push(child);
			}
		}
		else {
			// if alive return directly
			return successor;
		}
	}
}

void solve() {
	// solve here....

	int n;
	cin >> n;
	debug(n)


	/*

	graph is globally decared so need to be cleared
	if each testcase have a different graph, but it is
	not required in our case as we use same graph for each testcase

	*/

	for (int i = 0; i <= n; ++i)
	{
		graph[i].clear();
	}

	int root = -1;


	for (int i = 1; i <= n; i++) {

		int parent;
		cin >> parent;

		graph[parent].push_back(i);

		// we assume parent of root as 0 for simplicity
		if (parent == 0) root = i;

	}

	int q;
	cin >> q; // no. of queries

	// isAlive array to check status of a person (alive 1 /dead 0)
	vector<bool> isAlive(n + 1, 0); // n+1 size, 0 value to all initially.

	while (q--) {

		// creating isAlive array for each query

		for (int i = 1; i <= n; ++i)
		{
			bool status;
			cin >> status;

			isAlive[i] = status;
		}
		debug(isAlive)

		// calling the function aliveSuccessor and passing isAlive array and root

		cout << aliveSuccessor(isAlive, root) << nline;
	}
}


// ignore below code, can just call solve() function
// or write the whole solve() function code directly in main() function

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