#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
vector<int> g[N];

int depth[N];

void dfs(int vertex, int parent = 0) {

	/*
	take action on vertex after
	entering the vertex
	*/


	for (auto child : g[vertex]) {

		if (child == parent) continue;

		/*
		take action on child before
		entering the child node
		*/

		depth[child] = depth[vertex] + 1;

		dfs(child, vertex);


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

	dfs(10);

	int node = -1;
	int maxDepth = -1e9;

	for (int i = 1; i <= v; ++i)
	{
		if (maxDepth < depth[i]) {
			maxDepth = depth[i];
			node = i;
		}

		depth[i] = 0;
	}

	dfs(node);

	maxDepth = -1e9;

	for (int i = 1; i <= v; ++i)
	{
		if (maxDepth < depth[i]) {
			maxDepth = depth[i];
		}
	}

	cout << maxDepth << nline;
	return 0;
}