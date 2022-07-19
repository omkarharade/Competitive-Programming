#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
vector<int> g[N];
int subtree_sum[N];
int evenCnt[N];

void dfs(int vertex, int parent = -1) {

	/*
	take action on vertex after
	entering the vertex
	*/

	subtree_sum[vertex] = vertex;
	if (vertex % 2 == 0) evenCnt[vertex]++;

	for (auto child : g[vertex]) {

		/*
		take action on child before
		entering the child node
		*/

		if (child == parent) continue;
		dfs(child, vertex);

		subtree_sum[vertex] += subtree_sum[child];
		evenCnt[vertex] += evenCnt[child];

		/*
		take action on child after
		exiting the child node
		*/
	}

	/*
	take action on vertex before
	exiting the vertex
	*/

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int v;
	cin >> v;

	for (int i = 0; i < v - 1; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	dfs(1);

	int q;
	cin >> q;

	for (int i = 1; i <= v; ++i)
	{
		cout << subtree_sum[i] << " " << evenCnt[i] << nline;
	}

	// while(q--){

	// 	int v;
	// 	cin >> v;

	// 	cout << subtree_sum[v] << " " << evenCnt[v] << nline;

	// }

	return 0;
}