#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e3 + 10;
int graph1[N][N];

// vector<int> graph2[N];
vector<pair<int, int>> graph2[N];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;

		graph1[v1][v2] = 1;
		graph1[v2][v1] = 1;

		// graph2[v2].push_back(v1);
		// graph2[v1].push_back(v2);


		graph2[v2].push_back({v1, wt});
		graph2[v1].push_back({v2, wt});
	}

	/*   Adjacency List
		O(N^2) - space complexity
		N = 10^5

		Adjacency List
		O(N + M)
	*/

	return 0;
}